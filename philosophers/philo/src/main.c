/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:08:20 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/29 14:06:50 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: Check leaks and crashes using NULL for malloc, thread_init and mutex_init
// TODO: Make death message appear faster
// TODO: Add mutex to prevent philo dying and eating at the same time
// TODO: Handle n == 1 properly

int	main(int argc, char *argv[])
{
	t_env	*env;

	if (argc < 5 || argc > 7)
		return (printf("%s", MSG_USG), EXIT_SUCCESS);
	env = philo_init(argc, argv);
	if (!env)
		return (EXIT_FAILURE);
	thread_monitor(env);
	return (philo_exit(env), EXIT_SUCCESS);
}
