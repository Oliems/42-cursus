/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:06:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/01 15:47:53 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_server	t_server;
typedef struct s_client	t_client;

enum e_signals
{
	BIT0 = SIGUSR1,
	BIT1 = SIGUSR2,
	BIT_RECEIVED = SIGUSR1,
	STR_RECEIVED = SIGUSR2
};

enum e_messages
{
	USAGE,
	EMPTY,
	KILL_FAIL,
	MESSAGE_RECEIVED
};

struct s_client
{
	char	*s;
	pid_t	pid;
};

/* UTILS_1 */
int		ft_atoi(const char *nptr);
int		ft_isnumber(const char *s);

/* UTILS_0 */
int		ft_putnbr_fd(int64_t n, int fd);
int		ft_power(int nb, int power);
void	sig_message(int sig);

#endif
