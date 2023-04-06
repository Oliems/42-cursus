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

/**
 * @brief Initialize all mutexes in the mutex array representing the forks.
 * If an error occur when initializing a mutex, all mutexes previously
 * created are destroyed.
 * @param env Structure containing information about the program's
 * environment.
 * @param size The size of the array, i.e the number of philosophers.
 * @return 0 if everything was initialized properly, else returns 1.
 */
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

/**
 * @brief Create / initialize all threads in the thread array representing
 * the philosophers. If an error occur when creating a thread, all
 * threads previously created are destroyed.
 * @param env Structure containing information about the program's
 * environment.
 * @param size The size of the array, i.e the number of philosophers.
 * @return
 */
static int	threads_init(t_env *env, int size)
{
	int	i;

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

/**
 * @brief Transform the argument passed to the programed into ints. If the
 * limit (the number of times each philosopher must eat before the
 * simulation stops) is not specified, we set it to -1 so that the
 * comparison if (t->nmeal == t->env->arg[LIM]) at the end of thread_eat is
 * never true.
 * @param env Structure containing information about the program's
 * environment.
 * @param argc The number of arguments.
 * @param argv The values of the arguments.
 */
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

/**
 * @brief Create the environment (env) structur and set it to its defaults
 * values. If an error occurs at any point, everything is freed.
 * @param argc The number of arguments.
 * @param argv The values of the arguments.
 * @return A pointer to the initialized t_env struct or NULL if an error
 * occured.
 */
t_env	*philo_init(int argc, char *argv[])
{
	t_env	*p;

	p = allocator(f_atoi(argv[1]));
	if (!p)
		return (NULL);
	p->exit = false;
	philo_init_args(p, argc, argv);
	if (p->arg[N] <= 0 || p->arg[T2D] < 0 || p->arg[T2E] < 0
		|| p->arg[T2S] < 0 || p->arg[LIM] == 0)
		return (deallocator(p), printf("%s\n", MSG_NEG), NULL);
	if ((pthread_mutex_init(&(p->common_mtx), NULL)) != 0)
		return (deallocator(p), NULL);
	if (mutexes_init(p, p->arg[N]) || threads_init(p, p->arg[N]))
		return (deallocator(p), NULL);
	return (p);
}
