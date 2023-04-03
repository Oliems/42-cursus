/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:43:38 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:07:22 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	deallocator(t_env *env)
{
	if (!env)
		return ;
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

t_env	*allocator(size_t size)
{
	t_env	*p;

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

void	mutexes_destroy(t_env *env, int size)
{
	int	i;

	i = 0;
	if (!env->mtx)
		return ;
	while (i < size)
		pthread_mutex_destroy(&env->mtx[i++]);
	free(env->mtx);
	env->mtx = NULL;
}

void	threads_destroy(t_env *env, int size)
{
	int	i;

	i = 0;
	if (!env->thd)
		return ;
	while (i < size)
		pthread_join(env->thd[i++], NULL);
	free(env->thd);
	env->thd = NULL;
}

void	philo_exit(t_env *env)
{
	if (!env)
		return ;
	threads_destroy(env, env->arg[N]);
	mutexes_destroy(env, env->arg[N]);
	pthread_mutex_destroy(&env->common_mtx);
	deallocator(env);
}
