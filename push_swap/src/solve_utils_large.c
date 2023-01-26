/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:14:31 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/26 17:54:59 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	optimize_rotate(t_register *ra, t_register *rb, int action)
{
	if (action == RR)
	{
		if (find_gap(ra))
			perform_action(ra, rb, RR);
		else
			perform_action(ra, rb, RB);
	}
	else
	{
		if (ra->tail->index == ra->head->index - 1)
			perform_action(ra, rb, RRR);
		else
			perform_action(ra, rb, RRB);
	}
}

void	to_top_large(t_register *ra, t_register *rb, int k)
{
	int			med;

	med = (rb->size + (rb->size % 2 == 1)) / 2;
	if (k <= med)
		while (--k)
			optimize_rotate(ra, rb, RR);
	else if (k > med)
	{
		k = 1 + (rb->size - k);
		while (k--)
			optimize_rotate(ra, rb, RRR);
	}
}
