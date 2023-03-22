/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:14:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/22 12:26:32 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static int get_thread_id(void)
{
	static int id = 0;
	return (++id);
}

static void sync_time(t_env *env)
{
	while (time_now() <= env->start + 25)
	{
		usleep(1);
		continue;
	}
}

/*
 * Let n be the number of philosophers. If n is even then  n / 2
 * philosophers can eat at the same time. If n is odd then (n - 1) / 2
 * philosophers can eat at the same time. If n is even, even-numbered eat
 * first then odd-numbered. If n is odd, 1 eat first then even then odd.
*/
void *philo_thread_func(void *arg)
{
	t_thread		p;

	p.env = (t_env *)arg;
	pthread_mutex_lock(&(p.env->common_mtx));
	p.id = get_thread_id();
	pthread_mutex_unlock(&(p.env->common_mtx));
	sync_time(p.env); // FIXME: Does not work well for large number of threads
	p.start_time = time_now();
	printf("Thread %d started %ld ms ago\n", p.id, p.start_time - p.env->start);
	return (NULL);
}
