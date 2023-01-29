/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:03:27 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/27 18:07:50 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int main(int argc, char **argv)
{
	int srv_pid;

	if (argc != 3 || !ft_isnumber(argv[1]))
		return (write(STDERR_FILENO, "Usage: ./client <pid> <string>", 31));

	srv_pid = ft_atoi(argv[1]);
	ft_printf("server pid : %d", srv_pid);
	return (0);
}
