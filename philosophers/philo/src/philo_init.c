/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:26:32 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/22 12:09:00 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_exit(t_env *env)
{
	int i;

	i = 0;
	if (!env)
		return;
	if (env->th)
		while (i < env->np)
			pthread_join(env->th[i++], NULL);
	i = 0;
	if (env->mtx)
		while (i < env->np)
			pthread_mutex_destroy(&(env->mtx[i++]));
	free(env->th);
	free(env->mtx);
	env->th = NULL;
	env->mtx = NULL;
	free(env);
	env = NULL;
}

/* WARNING: if mutex are dynamicaly allocated, destroy all AND free array
AND return NULL if an error occured */
static pthread_mutex_t	*philo_init_mutexes(uint8_t size)
{
	int					i;
	pthread_mutex_t		*p;

	i = 0;
	p = malloc(size * sizeof(pthread_mutex_t));
	if (!p)
		return (NULL);
	while (i < size)
		p[i++] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	return (p);
}

static pthread_t	*philo_init_threads(t_env *env, uint8_t size)
{
	int			i;
	int			r;
	pthread_t	*p;

	i = 0;
	p = malloc(size * sizeof(pthread_t));
	if (!p)
		return (NULL);
	while (i < size)
	{
		r = pthread_create(&p[i], NULL, philo_thread_func, env);
		if (r != 0)
		{
			while (1)
			{
				pthread_join(p[i], NULL);
				if (!i)
					break ;
				i--;
			}
			return (free(p), NULL);
		}
		i++;
	}
	return (p);
}

static void philo_init_args(t_env *env, int argc, char *argv[])
{
	env->np = (uint8_t)f_atoi(argv[1]);
	env->td = f_atoi(argv[2]);
	env->te = f_atoi(argv[3]);
	env->ts = f_atoi(argv[4]);
	if (argc == 6)
		env->n = (uint16_t)f_atoi(argv[5]);
	else
		env->n = 0;
}

t_env *philo_init(int argc, char *argv[])
{
	t_env *p;

	p = malloc(sizeof(t_env));
	if (!p)
		return (NULL);
	philo_init_args(p, argc, argv);
	p->start = time_now();
	p->mtx = philo_init_mutexes(p->np);
	p->exit = false;
	if (!(p->mtx))
		return (free(p), NULL);
	if ((pthread_mutex_init(&(p->common_mtx), NULL)) != 0)
		return (philo_exit(p), NULL);
	p->th = philo_init_threads(p, p->np);
	if (!(p->th))
		return (philo_exit(p), NULL);
	return (p);
}
