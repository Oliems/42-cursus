/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:14:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:08:51 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thread_eat(t_thread *t, int fork1, int fork2)
{
	pthread_mutex_lock(&(t->env->mtx[fork1]));
	print_action(t, MSG_FORK);
	pthread_mutex_lock(&(t->env->mtx[fork2]));
	print_action(t, MSG_FORK);
	print_action(t, MSG_EAT);
	pthread_mutex_lock(&(t->env->common_mtx));
	t->env->last_meal[t->id] = time_now();
	pthread_mutex_unlock(&(t->env->common_mtx));
	my_usleep(t->env->arg[T2E]);
	pthread_mutex_unlock(&(t->env->mtx[fork1]));
	pthread_mutex_unlock(&(t->env->mtx[fork2]));
	t->nmeal++;
	if (t->nmeal == t->env->arg[LIM] && t->env->full[t->id] == false)
	{
		pthread_mutex_lock(&(t->env->common_mtx));
		t->env->full[t->id] = true;
		pthread_mutex_unlock(&(t->env->common_mtx));
	}
}

static void	thread_wait(t_thread *t)
{
	print_action(t, MSG_SLEEP);
	my_usleep(t->env->arg[T2S]);
	print_action(t, MSG_THINK);
}

static void	thread_routine(t_thread *t)
{
	if (t->env->arg[N] == 1) // FIXME: not very clean
		return ;
	while (!t->env->exit)
	{
		if (t->id % 2 == 1)
			thread_eat(t, t->id, (t->id + 1) % t->env->arg[N]);
		else
			thread_eat(t, (t->id + 1) % t->env->arg[N], t->id);
		thread_wait(t);
	}
	pthread_mutex_unlock(&(t->env->mtx[t->id]));
	pthread_mutex_unlock(&(t->env->mtx[(t->id + 1) % t->env->arg[N]]));
}

static void thread_barrier(t_env *env)
{
	static int count = 1;

	pthread_mutex_lock(&(env->common_mtx));
	count++;
	pthread_mutex_unlock(&(env->common_mtx));
	while (1)
	{
		pthread_mutex_lock(&(env->common_mtx));
		if (count == env->arg[N])
		{
			pthread_mutex_unlock(&(env->common_mtx));
			break;
		}
		pthread_mutex_unlock(&(env->common_mtx));
		usleep(100);
	}
}

void	*thread_init(void *arg)
{
	t_thread		t;
	static uint8_t	id = 0;

	t.env = (t_env *)arg;
	t.nmeal = 0;
	pthread_mutex_lock(&(t.env->common_mtx));
	t.id = id++;
	t.env->full[t.id] = false;
	t.env->last_meal[t.id] = t.env->start;
	pthread_mutex_unlock(&(t.env->common_mtx));
/* 	while (t.env->exit)
		; */
	thread_barrier(t.env);
	print_action(&t, MSG_THINK);
	thread_routine(&t);
	return (NULL);
}
