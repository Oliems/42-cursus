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

static void init_arr(t_env *env)
{
	int i;

	i = 0;
	while (i < env->arg[N])
	{
		env->last_meal[i] = env->start;
		env->full[i] = false;
		i++;
	}
}

// TODO: Handle n == 1 properly
// TODO: Make death message appear faster
// TODO: Remove my_usleep() if it proves unecessary
// TODO: Maybe reduce time usleep() in monitor_death
// TODO: Fix death seems to not occur at the right time, i.e simulation stops but should have stopped sooner, another philo should have died sooner
int	main(int argc, char *argv[])
{
	t_env	*env;

	if (argc < 5 || argc > 7)
		return (printf("%s", MSG_USG), EXIT_SUCCESS);
	env = philo_init(argc, argv);
	if (!env)
		return (printf("malloc() failed.\n"), EXIT_FAILURE);
	env->start = time_now();
	init_arr(env);
	thread_monitor(env);
	return (philo_exit(env), EXIT_SUCCESS);
}
