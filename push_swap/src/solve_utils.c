/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:30:25 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/26 16:10:48 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* Find the smallest index in a stack and return it.  */
int	find_low_index(t_register *r)
{
	int		i;
	t_node	*p;

	p = r->head;
	i = p->index;
	while (p)
	{
		if (p->index < i)
			i = p->index;
		p = p->next;
	}
	return (i);
}

/* Find the number with the lowest score and return the corresponding index. */
int	find_low_score(t_register *r)
{
	int		i;
	t_node	*p;
	t_node	*lo;

	p = r->head;
	lo = p;
	i = p->score;
	while (p)
	{
		if (p->score < i)
		{
			i = p->score;
			lo = p;
		}
		p = p->next;
	}
	return (lo->index);
}

/*
** Scan a stack looking for a gap > 1 between two consecutive indexes. If a
** gap is found, return the highest of the two indexes.
*/
int	find_gap(t_register *r)
{
	t_node	*p;
	int		gap;

	gap = 0;
	p = r->head;
	while (p && p->next && p->index != r->topi)
	{
		gap = p->next->index - p->index;
		if (gap != 1)
			return (p->next->index);
		p = p->next;
	}
	return (0);
}

/*
** Perform the appropriate action(s) to bring the number at position k to the
** top of the stack.
*/
void	to_top(t_register *ra, t_register *rb, int k, int stack)
{
	int			med;
	int			a[2];
	t_register	*p;

	p = ra;
	a[0] = RA;
	a[1] = RRA;
	if (stack == B)
	{
		p = rb;
		a[0] = RB;
		a[1] = RRB;
	}
	med = (p->size + (p->size % 2 == 1)) / 2;
	if (k <= med)
		while (--k)
			perform_action(ra, rb, a[0]);
	else if (k > med)
	{
		k = 1 + (p->size - k);
		while (k--)
			perform_action(ra, rb, a[1]);
	}
}

/*
** Return the position of the desired index relative to the top of the stack.
** Return 0 if the index is not found.
*/
int	locate_index(t_register *r, int i)
{
	int		po;
	t_node	*p;

	po = 1;
	p = r->head;
	while (p && p->index != i)
	{
		po++;
		p = p->next;
	}
	if (!p)
		return (0);
	return (po);
}
