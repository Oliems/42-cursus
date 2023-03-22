/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:06:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/22 11:43:16 by mbarberi         ###   ########.fr       */
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

# define USG_MSG "Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n"

typedef struct
{
	uint8_t				np;
	uint16_t			n;
	time_t				td;
	time_t				te;
	time_t				ts;
	time_t				start;
	pthread_t			*th;
	pthread_mutex_t		common_mtx;
	pthread_mutex_t		*mtx;
}	t_env;

/* PHILO_INIT.C */
t_env		*philo_init(int argc, char *argv[]);
void		philo_exit(t_env *env);

/* PHILO_THREAD.C */
void		*philo_thread_func(void *arg);

/* PHILO_HELPERS.C */
time_t		f_atoi(const char *s);
void		f_perror(const char *s);
time_t		time_now(void);

#endif
