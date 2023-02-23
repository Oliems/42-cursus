/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:07:31 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/23 15:13:19 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	solve(t_register *ra, t_register *rb)
{
	if (ra->size <= 5)
		return (solve_small(ra, rb));
	else
		return (solve_large(ra, rb));
}

int	main(int argc, char **argv)
{
	t_register	*ra;
	t_register	*rb;

	if (argc <= 2)
		exit(EXIT_SUCCESS);
	ra = malloc(sizeof(t_register));
	rb = malloc(sizeof(t_register));
	if (!ra || !rb)
		return (free(ra), free(rb), 1);
	if (check_arguments(argc, argv))
		return (free(ra), free(rb), write(2, "Error\n", 6));
	else
		setup(ra, rb, argc, argv);
	solve(ra, rb);
	return (free_all(ra), free_all(rb), 0);
}
