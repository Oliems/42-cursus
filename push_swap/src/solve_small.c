/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:13:35 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/23 18:06:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Solve a stack of size 3 with at most two operations. */
static void	solve_three(t_register *ra, t_register *rb)
{
	int	arr[3];

	arr[0] = ra->head->index;
	arr[1] = ra->head->next->index;
	arr[2] = ra->tail->index;
	if (arr[0] < arr[1])
	{
		if (arr[1] < arr[2])
			return ;
		else if (arr[0] < arr[2])
			return (perform_action(ra, rb, RRA), perform_action(ra, rb, SA));
		else if (arr[0] > arr[2])
			return (perform_action(ra, rb, RRA));
	}
	else if (arr[0] > arr[1])
	{
		if (arr[0] < arr[2])
			return (perform_action(ra, rb, SA));
		else if (arr[1] < arr[2])
			return (perform_action(ra, rb, RA));
		else if (arr[1] > arr[2])
			return (perform_action(ra, rb, RA), perform_action(ra, rb, SA));
	}
}

static void	solve_four(t_register *ra, t_register *rb)
{
	int     i;
	int		c;
	t_node *p;

	c = 1;
	p = ra->head;
	i = find_low_index(ra);
	while (p && (p->index != i))
	{
		c++;
		p = p->next;
	}
	to_top(ra, rb, c, A);
	if (is_sorted(ra))
		return ;
	perform_action(ra, rb, PB);
	solve_three(ra, rb);
	perform_action(ra, rb, PA);
}

/* TODO Find the two smallest numbers so that we can extract whichever is
closest to the top, might save a few moves */
static void	solve_five(t_register *ra, t_register *rb)
{
	int     i;
	int		c;
	t_node *p;

	c = 1;
	p = ra->head;
	i = find_low_index(ra);
	while (p && (p->index != i))
	{
		c++;
		p = p->next;
	}
	to_top(ra, rb, c, A);
	if (is_sorted(ra))
		return ;
	perform_action(ra, rb, PB);
	solve_four(ra, rb);
	perform_action(ra, rb, PA);
}

void solve_small(t_register *ra, t_register *rb)
{
	if (is_sorted(ra))
		return ;
	if (ra->size == 3)
		return (solve_three(ra, rb));
	if (ra->size == 4)
		return (solve_four(ra, rb));
	if (ra->size == 5)
		return (solve_five(ra, rb));
}
