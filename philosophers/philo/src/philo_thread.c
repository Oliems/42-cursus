/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:14:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/20 13:23:53 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int get_philo_id(t_env *env)
{
	static int id = 0;
	return (++id);
}

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
