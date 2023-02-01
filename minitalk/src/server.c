/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:08:20 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/01 19:42:10 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

/** @brief Signal handler, called whenever SIGUSR1 or SIGUSR2 is received.
 * Compute and print the character corresponding to the bits received.
 *  @param sig The signal received, either SIGUSR1 or SIGUSR2.
 *  @param si Structure containing information about the signal's sender.
 *  @param ucontext Placeholder since sa_sigaction expects a void * as its
 * third argument.
 */
static void	receive_bit(int sig, siginfo_t *si, void *ucontext)
{
	static unsigned char	c = 0;
	static unsigned char	mask = 0x80;

	(void)ucontext;
	if (kill(si->si_pid, 0) < 0)
		sig_message(KILL_FAIL);
	if (!mask)
	{
		if (c)
			write(STDOUT_FILENO, &c, 1);
		c = 0;
		mask = 0x80;
	}
	if (sig == BIT1)
		c ^= mask;
	mask >>= 1;
	kill(si->si_pid, BIT_RECEIVED);
	if (!c && !mask)
	{
		write(1, "\n", 1);
		kill(si->si_pid, NULL_RECEIVED);
	}
}

/**
 * @brief Set up the structure to be used by sigaction(2). This allows us
 * to get the sender's pid using the siginfo_t struct so that we can send a
 * response from the handler.
 * @param sig The signal received, either SIGUSR1 or SIGUSR2.
 * @param h The handler function to call whenever SIGUSR1 or SIGUSR2 is
 * received.
 */
static void	setup_signal(int sig, void (*h)(int, siginfo_t *, void *))
{
	struct sigaction	sa;

	sa.sa_sigaction = h;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	if (sig == SIGUSR1)
		sigaction(SIGUSR1, &sa, 0);
	else if (sig == SIGUSR2)
		sigaction(SIGUSR2, &sa, 0);
}

int	main(void)
{
	setup_signal(SIGUSR1, receive_bit);
	setup_signal(SIGUSR2, receive_bit);
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	while (1)
		sleep(1);
}
