/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:22:26 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/01 19:09:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static uint64_t	ft_abs(int64_t i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	ft_putnbr_fd(int64_t n, int fd)
{
	int		i;
	int		r;
	char	num[32];

	i = 0;
	r = 0;
	if (!n)
		return (write(fd, "0", 1));
	if (n < 0)
		r += write(fd, "-", 1);
	n = ft_abs(n);
	while (n)
	{
		num[i++] = n % 10 + '0';
		n /= 10;
	}
	while (--i >= 0)
		r += write(fd, &num[i], 1);
	return (r);
}

void	sig_message(int sig)
{
	if (sig == USAGE)
	{
		write(STDERR_FILENO, "Usage: ./client <pid> <string>", 31);
		exit(EXIT_SUCCESS);
	}
	else if (sig == NULL_ARG)
	{
		write(STDERR_FILENO, "Error ARG2 is (null)", 21);
		exit(EXIT_SUCCESS);
	}
	else if (sig == KILL_FAIL)
	{
		write(STDERR_FILENO, "Error can't send signal.", 25);
		exit(EXIT_FAILURE);
	}
	else if (sig == MESSAGE_RECEIVED)
	{
		write(STDOUT_FILENO, "Message received.\n", 19);
		exit(EXIT_SUCCESS);
	}
}
