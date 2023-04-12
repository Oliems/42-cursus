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
	print_action(t->env, t->id, MSG_FORK);
	pthread_mutex_lock(&(t->env->mtx[fork2]));
	print_action(t->env, t->id, MSG_FORK);
	print_action(t->env, t->id, MSG_EAT);
	pthread_mutex_lock(&(t->env->common_mtx));
	t->env->last_meal[t->id] = time_now();
	pthread_mutex_unlock(&(t->env->common_mtx));
	my_usleep(t->env->arg[T2E]);
	pthread_mutex_unlock(&(t->env->mtx[fork1]));
	pthread_mutex_unlock(&(t->env->mtx[fork2]));
	t->nmeal++;
	if (t->nmeal == t->env->arg[LIM] && t->full == false)
	{
		pthread_mutex_lock(&(t->env->common_mtx));
		t->full = true;
		t->env->nfull += 1;
		pthread_mutex_unlock(&(t->env->common_mtx));
	}
}

static void	thread_wait(t_thread *t)
{
	print_action(t->env, t->id, MSG_SLEEP);
	my_usleep(t->env->arg[T2S]);
	print_action(t->env, t->id, MSG_THINK);
}

/**
 * @brief The main loop of the thread. We use delta to introduce a waiting
 * period proportional to the parameters passed to the program. This allows
 * us to intoduce a bit of of asynchronicity which makes to program perform
 * much better, especially for high / odd number of threads.
 * @param t A struct containing the philosopher's information.
 */
static void	thread_routine(t_thread *t)
{
	time_t	delta;

	delta = t->env->arg[T2D] - (t->env->arg[T2E] + t->env->arg[T2S]);
	while (1)
	{
		if (t->id % 2 == 0)
			my_usleep(delta * 0.33);
		pthread_mutex_lock(&(t->env->common_mtx));
		if (t->env->exit)
		{
			pthread_mutex_unlock(&(t->env->common_mtx));
			break ;
		}
		pthread_mutex_unlock(&(t->env->common_mtx));
		if (t->id % 2 == 1)
			thread_eat(t, t->id, (t->id + 1) % t->env->arg[N]);
		else
			thread_eat(t, (t->id + 1) % t->env->arg[N], t->id);
		thread_wait(t);
	}
}

/**
 * @brief Simple barrier implementation, it locks threads in the barrier
 * until all threads have arrived.
 * @param n The quorum i.e the number of threads to wait for before all
 * threads can exit the function.
 */
static void	thread_barrier(int n)
{
	static int				count = 0;
	static pthread_mutex_t	barrier_mtx = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&(barrier_mtx));
	count++;
	pthread_mutex_unlock(&(barrier_mtx));
	while (1)
	{
		pthread_mutex_lock(&(barrier_mtx));
		if (count == n)
		{
			pthread_mutex_unlock(&(barrier_mtx));
			break ;
		}
		pthread_mutex_unlock(&(barrier_mtx));
		usleep(150);
	}
}

void	*thread_init(void *arg)
{
	t_thread				t;
	static int				id = 0;
	static pthread_mutex_t	init_mtx = PTHREAD_MUTEX_INITIALIZER;

	t.env = (t_env *)arg;
	if (t.env->arg[N] == 1)
	{
		pthread_mutex_lock(&(t.env->common_mtx));
		printf("%ld %d %s\n", 0L, 1, MSG_FORK);
		pthread_mutex_unlock(&(t.env->common_mtx));
		pthread_mutex_lock(&(t.env->mtx[0]));
		pthread_mutex_unlock(&(t.env->mtx[0]));
		return (NULL);
	}
	t.nmeal = 0;
	t.full = false;
	pthread_mutex_lock(&(init_mtx));
	t.id = id++;
	pthread_mutex_unlock(&(init_mtx));
	thread_barrier(t.env->arg[N]);
	print_action(t.env, t.id, MSG_THINK);
	thread_routine(&t);
	return (NULL);
}
