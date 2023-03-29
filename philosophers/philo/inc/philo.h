/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:06:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:09:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdbool.h>

# define MSG_USG "Usage: ./philo <number_of_philosophers> <time_to_die> \
<time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"
# define MSG_EAT "is eating"
# define MSG_SLEEP "is sleeping"
# define MSG_THINK "is thinking"
# define MSG_FORK "has taken a fork"
# define MSG_DIE "has died"
# define MSG_NEG "Please enter a non-negative value."

typedef struct s_env	t_env;
typedef struct s_thread	t_thread;

enum
{
	N,
	T2D,
	T2E,
	T2S,
	LIM
};

struct s_thread
{
	uint8_t		id;
	t_env		*env;
	int			nmeal;
};

struct s_env
{
	int					*arg;
	time_t				*last_meal;
	bool				*full;
	pthread_mutex_t		*mtx;
	pthread_t			*thd;
	time_t				start;
	bool				exit;
	pthread_mutex_t		common_mtx;

};

/* INIT.C */
t_env		*philo_init(int argc, char *argv[]);
void		philo_exit(t_env *env);

/* HELPERS.C */
time_t		f_atoi(const char *s);

/* THREAD.C */
void		*thread_init(void *arg);
void		thread_monitor(t_env *env);

/* THREAD_HELPERS.C */
time_t		time_now(void);
void		my_usleep(time_t wait);
void		print_action(t_thread *t, char *act);

/* THREAD_MONITOR.C */
void		thread_monitor(t_env *env);

/* MEMORY.C */
void		deallocator(t_env *env);
t_env		*allocator(size_t size);
void		mutexes_destroy(t_env *env, uint8_t size);
void		threads_destroy(t_env *env, uint8_t size);
void		philo_exit(t_env *env);

#endif
