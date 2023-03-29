/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:12:50 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 12:35:00 by mbarberi         ###   ########.fr       */
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
