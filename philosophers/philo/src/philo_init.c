/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:26:32 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/28 18:47:08 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void deallocator(t_env *env)
{
	if (!env)
		return;
	if (env->mtx)
		free(env->mtx);
	if (env->thd)
		free(env->thd);
	if (env->last_meal)
		free(env->last_meal);
	if (env->full)
		free(env->full);
	if (env->arg)
		free(env->arg);
	env->mtx = NULL;
	env->thd = NULL;
	env->last_meal = NULL;
	env->full = NULL;
	env->arg = NULL;
	free(env);
	env = NULL;
}

static t_env *allocator(size_t size)
{
	t_env *p;

	if (!size)
		return (NULL);
	p = malloc(sizeof(t_env));
	if (!p)
		return (NULL);
	p->mtx = malloc(size * sizeof(pthread_mutex_t));
	p->thd = malloc(size * sizeof(pthread_t));
	p->last_meal = malloc(size * sizeof(time_t));
	p->full = malloc(size * sizeof(bool));
	p->arg = malloc(5 * sizeof(int));
	if (!(p->mtx) || !(p->thd) || !(p->last_meal) || !(p->full) || !(p->arg))
		return (deallocator(p), NULL);
	return (p);
}

static void mutexes_destroy(t_env *env, uint8_t size)
{
	int i;

	i = 0;
	if (!env->mtx)
		return;
	while (i < size)
		pthread_mutex_destroy(&env->mtx[i++]);
	free(env->mtx);
	env->mtx = NULL;
}

// FIXME: Might not work if threads are busy
static void threads_destroy(t_env *env, uint8_t size)
{
	int i;

	i = 0;
	if (!env->thd)
		return;
	while (i < size)
		pthread_join(env->thd[i++], NULL);
	free(env->thd);
	env->thd = NULL;
}

void philo_exit(t_env *env)
{
	if (!env)
		return;
	threads_destroy(env, env->arg[N]);
	mutexes_destroy(env, env->arg[N]);
	pthread_mutex_destroy(&env->common_mtx);
	deallocator(env);
}

static int mutexes_init(t_env *env, uint8_t size)
{
	int i;

	if (!env->mtx)
		return (1);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&env->mtx[i], NULL) != 0)
			return (mutexes_destroy(env, i), 1);
		i++;
	}
	return (0);
}

static int threads_init(t_env *env, uint8_t size)
{
	int i;

	if (!env->thd)
		return (1);
	i = 0;
	while (i < size)
	{
		if (pthread_create(&env->thd[i], NULL, thread_begin, env) != 0)
			return (threads_destroy(env, i), 1);
		i++;
	}
	return (0);
}

static void philo_init_args(t_env *env, int argc, char *argv[])
{
	env->arg[N] = f_atoi(argv[1]);
	env->arg[T2D] = f_atoi(argv[2]);
	env->arg[T2E] = f_atoi(argv[3]);
	env->arg[T2S] = f_atoi(argv[4]);
	if (argc == 6)
		env->arg[LIM] = f_atoi(argv[5]);
	else
		env->arg[LIM] = -1;
}

// TODO: Initialize p->full and p->last_meal
static void philo_init_meal(t_env *env)
{
	int i;

	i = 0;
	while (i < env->arg[N])
		env->last_meal[i++] = env->start;
}

t_env *philo_init(int argc, char *argv[])
{
	t_env *p;

	p = allocator(f_atoi(argv[1]));
	if (!p)
		return (NULL);
	philo_init_args(p, argc, argv);
	if (p->arg[N] <= 0 || p->arg[T2D] < 0 || p->arg[T2E] < 0 || p->arg[T2S] < 0 || p->arg[LIM] == 0)
		return (deallocator(p), printf("Please enter a non-negative value."), NULL);
	p->exit = true;
	if ((pthread_mutex_init(&(p->common_mtx), NULL)) != 0)
		return (deallocator(p), NULL);
	if (mutexes_init(p, p->arg[N]) || threads_init(p, p->arg[N]))
		return (deallocator(p), NULL);
	p->start = time_now();
	philo_init_meal(p);
	p->exit = false;
	return (p);
}
