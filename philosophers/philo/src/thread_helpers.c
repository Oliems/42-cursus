/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:23:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/28 16:42:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void my_usleep(time_t wait)
{
	time_t	t;

	t = time_now();
	while ((time_now() - t) < wait)
		usleep(150);
}

void print_action(t_thread *t, char *act)
{
	pthread_mutex_lock(&(t->env->common_mtx));
	if (!t->env->exit)
		printf("%ld %d %s\n", time_now() - t->env->start, t->id + 1, act);
	pthread_mutex_unlock(&(t->env->common_mtx));
}
