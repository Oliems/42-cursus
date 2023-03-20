/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 22:08:20 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/20 11:28:17 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * Let n be the number of philosophers. If n is even then  n / 2
 * philosophers can eat at the same time. If n is odd then (n - 1) / 2
 * philosophers can eat at the same time. If n is even, even-numbered eat
 * first then odd-numbered. If n is odd, 1 eat first then even then odd.
*/
int main(int argc, char *argv[])
{
	t_env *env;

	if (argc < 5 || argc > 7)
		return (f_perror(USG_MSG), EXIT_SUCCESS);
	env = philo_init(argc, argv);
	if (!env)
		return (f_perror("Error\n"), EXIT_FAILURE);
	return (philo_exit(env), EXIT_SUCCESS);
}
