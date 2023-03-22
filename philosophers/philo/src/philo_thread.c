/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:14:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/22 11:46:43 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int get_philo_id(void)
{
	static int id = 0;
	return (++id);
}



static void sync_time(t_env *env)
{
	while (time_now() < env->start + 20)
		continue;
}

/*
 * Let n be the number of philosophers. If n is even then  n / 2
 * philosophers can eat at the same time. If n is odd then (n - 1) / 2
 * philosophers can eat at the same time. If n is even, even-numbered eat
 * first then odd-numbered. If n is odd, 1 eat first then even then odd.
*/
void *philo_thread_func(void *arg)
{
	int			id;
	t_env		*env;

	env = (t_env *)arg;
	pthread_mutex_lock(&(env->common_mtx));
	id = get_philo_id();
	pthread_mutex_unlock(&(env->common_mtx));
	sync_time(env);
	printf("Thread %d started %ld ms ago\n", id, time_now() - env->start);
	return (NULL);
}
