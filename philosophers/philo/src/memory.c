/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 12:43:38 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:07:22 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Free each member of the struct and the struct itself.
 * @param env Structure containing information about the program's
 * environment.
 */
void	deallocator(t_env *env)
{
	if (!env)
		return ;
	if (env->mtx)
		free(env->mtx);
	if (env->thd)
		free(env->thd);
	if (env->last_meal)
		free(env->last_meal);
	if (env->arg)
		free(env->arg);
	env->mtx = NULL;
	env->thd = NULL;
	env->last_meal = NULL;
	env->arg = NULL;
	free(env);
	env = NULL;
}

/**
 * @brief Allocate the env struct and its members. If an error occurs
 * during one the call to malloc(), everything if free'd.
 * @param size The size of the arrays, i.e the number of philosophers.
 * @return A pointer to a t_env struct or NULL if an error occured.
 */
t_env	*allocator(size_t size)
{
	t_env	*p;

	if (!size)
		return (NULL);
	p = malloc(sizeof(t_env));
	if (!p)
		return (NULL);
	p->mtx = malloc(size * sizeof(pthread_mutex_t));
	p->thd = malloc(size * sizeof(pthread_t));
	p->last_meal = malloc(size * sizeof(time_t));
	p->arg = malloc(5 * sizeof(int));
	if (!(p->mtx) || !(p->thd) || !(p->last_meal) || !(p->arg))
		return (deallocator(p), NULL);
	return (p);
}

/**
 * @brief Destroy all mutexes and free the array.
 * @param env Structure containing information about the program's
 * environment.
 * @param size The size of the array, i.e the number of philosophers.
 */
void	mutexes_destroy(t_env *env, int size)
{
	int	i;

	i = 0;
	if (!env->mtx)
		return ;
	while (i < size)
		pthread_mutex_destroy(&env->mtx[i++]);
	free(env->mtx);
	env->mtx = NULL;
}

/**
 * @brief Join all threads and free the array.
 * @param env Structure containing information about the program's
 * environment.
 * @param size The size of the array, i.e the number of philosophers.
 */
void	threads_destroy(t_env *env, int size)
{
	int	i;

	i = 0;
	if (!env->thd)
		return ;
	while (i < size)
		pthread_join(env->thd[i++], NULL);
	free(env->thd);
	env->thd = NULL;
}

/**
 * @brief Free everything.
 * @param env Structure containing information about the program's
 * environment.
 */
void	philo_exit(t_env *env)
{
	if (!env)
		return ;
	threads_destroy(env, env->arg[N]);
	mutexes_destroy(env, env->arg[N]);
	pthread_mutex_destroy(&env->common_mtx);
	deallocator(env);
}
