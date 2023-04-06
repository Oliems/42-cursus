/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:07:30 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	my_usleep(time_t wait)
{
	time_t	start;

	start = time_now();
	while ((time_now() - start) < wait)
		usleep(100);
}

void	print_action(t_env *env, int id, char *act)
{
	pthread_mutex_lock(&(env->common_mtx));
	if (!env->exit)
		printf("%ld %d %s\n", time_now() - env->start, id + 1, act);
	pthread_mutex_unlock(&(env->common_mtx));
}
