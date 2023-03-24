/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:14:03 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/23 16:21:05 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void my_usleep(time_t time)
{
	time_t	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < time)
		usleep(25); // was 150
}

static void print_action(t_thread *t, char *act)
{
	pthread_mutex_lock(&(t->env->common_mtx));
	printf("%ld %d %s\n", time_now() - t->start_time, t->id, act);
	pthread_mutex_unlock(&(t->env->common_mtx));
}

static void thread_eat(t_thread *t)
{
	if (t->full)
		return;
	pthread_mutex_lock(&(t->env->mtx[t->id]));
	print_action(t, MSG_FORK);
	pthread_mutex_lock(&(t->env->mtx[t->id - 1]));
	print_action(t, MSG_FORK);
	my_usleep(t->env->te);
	t->last_meal = time_now();
	print_action(t, MSG_EAT);
	pthread_mutex_unlock(&(t->env->mtx[t->id]));
	pthread_mutex_unlock(&(t->env->mtx[t->id - 1]));
	t->nmeal++;
	if (t->nmeal == t->env->n)
		t->full = true;
}

static void thread_wait(t_thread *t)
{
	my_usleep(t->env->ts);
	print_action(t, MSG_SLEEP);
	print_action(t, MSG_THINK);
}

static void thread_routine_even(t_thread *t)
{
	static int whose_turn = EVEN;
	static uint8_t nfull = 0;

	if (t->env->exit || nfull == t->env->np || check_death(t))
	{
		// printf("nfull = %d\n", nfull);
		pthread_mutex_lock(&(t->env->common_mtx));
		t->env->exit = true;
		pthread_mutex_unlock(&(t->env->common_mtx));
		return;
	}
	thread_eat(t);
	if (t->full)
	{
		pthread_mutex_lock(&(t->env->common_mtx));
		nfull++;
		pthread_mutex_unlock(&(t->env->common_mtx));
	}
	thread_wait(t);
}

/*
 * Let n be the number of philosophers. If n is even then  n / 2
 * philosophers can eat at the same time. If n is odd then (n - 1) / 2
 * philosophers can eat at the same time. If n is even, even-numbered eat
 * first then odd-numbered. If n is odd, 1 eat first then even then odd.
*/
void *philo_thread_func(void *arg)
{
	t_thread		t;
	static uint8_t	id = 1;

	t.env = (t_env *)arg;
	t.full = false;
	pthread_mutex_lock(&(t.env->common_mtx));
	t.id = id++;
	pthread_mutex_unlock(&(t.env->common_mtx));
	while (!t.env->go)
		usleep(1);
	t.start_time = time_now();
	while (!t.env->exit)
	{
		if (t.env->np % 2 == 0)
			thread_routine_even(&t);
		else
		{
			if (t.id == 1)
				my_usleep(t.env->te * 0.9 + 1);
			thread_routine_even(&t);
		}
	}
	return (NULL);
}
