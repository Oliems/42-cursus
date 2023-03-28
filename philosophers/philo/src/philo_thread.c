/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:14:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/28 19:00:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int thread_monitor_full(t_env *env)
{
	int c;
	int i;

	i = 0;
	c = 0;
	pthread_mutex_lock(&(env->common_mtx));
	while (i < env->arg[N])
	{
		if (env->full[i] == true)
			c++;
		i++;
	}
	if (c == env->arg[N])
	{
		printf("All philosophers have eaten %d times.\n", env->arg[LIM]);
		env->exit = true;
		pthread_mutex_unlock(&(env->common_mtx));
		return (1);
	}
	pthread_mutex_unlock(&(env->common_mtx));
	return (0);
}

// FIXME:
static int thread_monitor_death(t_env *env)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(env->common_mtx));
	while (i < env->arg[N])
	{
		if (time_now() - env->last_meal[i] >= env->arg[T2D])
		{
			printf("%ld %d %s\n", time_now() - env->start, i + 1, MSG_DIE);
			env->exit = true;
			pthread_mutex_unlock(&(env->common_mtx));
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&(env->common_mtx));
	return (0);
}

void thread_monitor(t_env *env)
{
	while (1)
	{
		if (thread_monitor_full(env))
			break;
		if (thread_monitor_death(env))
			break;
	}
}

// TODO nmeal could be replaced by incrementing value in array and checking if all value in the array == lim
static void thread_eat(t_thread *t, int fork1, int fork2)
{
	pthread_mutex_lock(&(t->env->mtx[fork1]));
	print_action(t, MSG_FORK);
	pthread_mutex_lock(&(t->env->mtx[fork2]));
	print_action(t, MSG_FORK);
	print_action(t, MSG_EAT);
	pthread_mutex_lock(&(t->env->common_mtx));
	t->env->last_meal[t->id] = time_now();
	pthread_mutex_unlock(&(t->env->common_mtx));
	my_usleep(t->env->arg[T2E]);
	pthread_mutex_unlock(&(t->env->mtx[fork1]));
	pthread_mutex_unlock(&(t->env->mtx[fork2]));
	t->nmeal++;
	if (t->nmeal == t->env->arg[LIM] && t->env->full[t->id] == false)
	{
		pthread_mutex_lock(&(t->env->common_mtx));
		t->env->full[t->id] = true;
		pthread_mutex_unlock(&(t->env->common_mtx));
	}
}

static void thread_wait(t_thread *t)
{
	print_action(t, MSG_SLEEP);
	my_usleep(t->env->arg[T2S]);
	print_action(t, MSG_THINK);
}

static void philo_routine(t_thread *t)
{
	while (!t->env->exit)
	{
		if (t->id % 2 == 1)
			thread_eat(t, t->id, (t->id + 1) % t->env->arg[N]);
		else
			thread_eat(t, (t->id + 1) % t->env->arg[N], t->id);
		thread_wait(t);
	}
	pthread_mutex_unlock(&(t->env->mtx[t->id]));
	pthread_mutex_unlock(&(t->env->mtx[(t->id + 1) % t->env->arg[N]]));
}

void *thread_begin(void *arg)
{
	t_thread		t;
	static uint8_t	id = 0;

	t.env = (t_env *)arg;
	t.nmeal = 0;
	pthread_mutex_lock(&(t.env->common_mtx));
	t.id = id++;
	pthread_mutex_unlock(&(t.env->common_mtx));
	while (t.env->exit)
		;
	print_action(&t, MSG_THINK);
	philo_routine(&t);
	return (NULL);
}
