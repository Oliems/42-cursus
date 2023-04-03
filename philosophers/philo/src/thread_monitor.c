/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:12:50 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:07:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	thread_monitor_full(t_env *env)
{
	int	c;
	int	i;

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
	my_usleep(1.25 * (env->arg[T2E] + env->arg[T2S]));
	return (0);
}

static int	thread_monitor_death(t_env *env)
{
	int			i;
	time_t		now;
	time_t		delta;

	i = 0;
	now = time_now();
	pthread_mutex_lock(&(env->common_mtx));
	while (i < env->arg[N])
	{
		delta = now - env->last_meal[i];
		if (delta >= env->arg[T2D])
		{
			printf("%ld %d %s\n", now - env->start, i + 1, MSG_DIE);
			env->exit = true;
			pthread_mutex_unlock(&(env->common_mtx));
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&(env->common_mtx));
	usleep(1000);
	return (0);
}

void	thread_monitor(t_env *env)
{
	while (1)
	{
		if (thread_monitor_full(env))
			break ;
		if (thread_monitor_death(env))
			break ;
	}
}
