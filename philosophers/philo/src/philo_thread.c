/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:14:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/20 13:51:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int get_philo_id(t_env *env)
{
	static int id = 0;
	return (++id);
}

static time_t	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
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
	id = get_philo_id(env);
	printf("Hello from thread %d\n", id);
	pthread_mutex_unlock(&(env->common_mtx));
	return (NULL);
}
