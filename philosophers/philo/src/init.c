/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:26:32 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:08:28 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	mutexes_init(t_env *env, int size)
{
	int	i;

	if (!env->mtx)
		return (1);
	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&env->mtx[i], NULL) != 0)
			return (mutexes_destroy(env, i), 1);
		i++;
	}
	return (0);
}

static int threads_init(t_env *env, int size)
{
	int i;

	if (!env->thd)
		return (1);
	i = 0;
	while (i < size)
	{
		if (pthread_create(&env->thd[i], NULL, thread_init, env) != 0)
			return (threads_destroy(env, i), 1);
		i++;
	}
	return (0);
}

static void	philo_init_args(t_env *env, int argc, char *argv[])
{
	env->arg[N] = f_atoi(argv[1]);
	env->arg[T2D] = f_atoi(argv[2]);
	env->arg[T2E] = f_atoi(argv[3]);
	env->arg[T2S] = f_atoi(argv[4]);
	if (argc == 6)
		env->arg[LIM] = f_atoi(argv[5]);
	else
		env->arg[LIM] = -1;
}

t_env	*philo_init(int argc, char *argv[])
{
	t_env	*p;

	p = allocator(f_atoi(argv[1]));
	if (!p)
		return (NULL);
	philo_init_args(p, argc, argv);
	p->start = time_now();
	p->exit = false;
	if (p->arg[N] <= 0 || p->arg[T2D] < 0 || p->arg[T2E] < 0
		|| p->arg[T2S] < 0 || p->arg[LIM] == 0)
		return (deallocator(p), printf("%s\n", MSG_NEG), NULL);
	if ((pthread_mutex_init(&(p->common_mtx), NULL)) != 0)
		return (deallocator(p), NULL);
	if (mutexes_init(p, p->arg[N]) || threads_init(p, p->arg[N]))
		return (deallocator(p), NULL);
	return (p);
}
