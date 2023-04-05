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
	if (env->nfull == env->arg[N])
	{
		printf("All philosophers have eaten %d times.\n", env->arg[LIM]);
		env->exit = true;
		return (1);
	}
	return (0);
}

static int	thread_monitor_death(t_env *env, int i, int j)
{
	time_t	now;
	time_t	delta1;
	time_t	delta2;

	now = time_now();
	delta1 = now - env->last_meal[i];
	delta2 = now - env->last_meal[j];
	if (delta1 >= env->arg[T2D])
	{
		printf("%ld %d %s\n", now - env->start, i + 1, MSG_DIE);
		env->exit = true;
		return (1);
	}
	else if (delta2 >= env->arg[T2D])
	{
		printf("%ld %d %s\n", now - env->start, j + 1, MSG_DIE);
		env->exit = true;
		return (1);
	}
	return (0);
}

void	thread_monitor(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = env->arg[N] - 1;
	while (1)
	{
		if (i >= j)
		{
			i = 0;
			j = env->arg[N] - 1;
		}
		pthread_mutex_lock(&(env->common_mtx));
		if (thread_monitor_death(env, i, j) || thread_monitor_full(env))
		{
			pthread_mutex_unlock(&(env->common_mtx));
			return ;
		}
		pthread_mutex_unlock(&(env->common_mtx));
		i++;
		j--;
		usleep(100);
	}
}
