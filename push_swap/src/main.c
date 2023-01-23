/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:07:31 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/23 18:06:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_register	*ra;
	t_register	*rb;

	ra = malloc(sizeof(t_register));
	rb = malloc(sizeof(t_register));
	if (argc <= 2 || !ra || !rb)
		return (0);
	if (check_arguments(argc, argv))
		return (write(2, "Error\n", 6));
	else
		setup(ra, rb, argc, argv);
	solve(ra, rb);
	// free everything
	return (0);
}
