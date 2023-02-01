/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:03:27 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/01 19:34:25 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static volatile sig_atomic_t	g_received = 0;

/**
 * @brief SIGUSR1 indicates that the server as successfully processed a
 * bit, SIGUSR2 indicates that the server as received a null byte and thus
 * as printed the whole string.
 * @param sig The signal received from the server.
 */
static void	signal_handler(int sig)
{
	g_received = sig;
	if (sig == NULL_RECEIVED)
		sig_message(MESSAGE_RECEIVED);
}

/**
 * @brief Send a single character to the server.
 * @param c The char to send.
 * @param pid The server's pid.
 */
static void	send_char(char c, int pid)
{
	unsigned char	mask;

	mask = 0x80;
	if (kill(pid, 0) < 0)
		sig_message(KILL_FAIL);
	while (mask)
	{
		g_received = 0;
		if (c & mask)
			kill(pid, BIT1);
		else
			kill(pid, BIT0);
		mask >>= 1;
		while (!g_received)
			usleep(10);
	}
}

/**
 * @brief Send a string to the server, character by character.
 * @param s The string to send.
 * @param pid The server's pid.
 */
static void	send_string(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
		send_char(s[i++], pid);
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_isnumber(argv[1]))
		sig_message(USAGE);
	if (!(argv[2]))
		sig_message(NULL_ARG);
	else
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		send_string(argv[2], ft_atoi(argv[1]));
	}
	while (1)
		sleep(1);
}
