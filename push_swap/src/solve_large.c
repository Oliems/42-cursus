/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_large.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:19:24 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/24 17:47:36 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// ../../../../push_swap

/*
+ Phase 1
    + Divide the maximum index by 3 (3 slices for n = 100, 6 slices for n =
      500).
    + Push the two smallest thirds onto stack B. For example if we have 100
      numbers, we need to push numbers with indexes 1 to 66 to B. If the
      number's index belongs to the first third (in the previous example if
      its index is < 33 ), we send it to the bottom of B, else leave it on
      top.
    + Repeat the previous steps until there are only three numbers left in
      stack A. Those three numbers will be the three number with the
      highest indexes.
    + Sort these three numbers using a specific algorithm (two operations
      maximum).
+ Phase 2
    + Only the ra, rra, rb and rrb operations are used in this phase.
    + Scan B looking for the number that will take the fewest moves to be
      pushed into A.
        + There are four ways to bring a number from B to A: rr, ra+rrb,
          rra+rb, rrr. We are looking for the minimum between these four
          ways.
    + Perform the operation.
    + Repeat the previous steps until B is empty.
+ Phase 3
    + If necessary, use ra or rra (whichever will take less operations) to
      put A in the correct order.
    + The optimization comes from the fact of the maximum use of the double
      rotations rr and rrr.
*/

static int	pick_slice_size(t_register *ra, t_register *rb)
{
	int	size;

	size = ra->size + rb->size;
	if ((size > 5) && (size <= 400))
		return (2 * (ra->size / 3));
	else if (size > 400 && size <= 800)
		return (4 * (ra->size / 6));
	else if (size > 800)
		return (6 * (ra->size / 9));
	return (2 * (ra->size / 3));
}

static void	push_slice(t_register *ra, t_register *rb)
{
	int	lo;
	int	up;

	up = 0;
	while (1)
	{
		lo = up;
		up += pick_slice_size(ra, rb);
		while (rb->size != up)
		{
			while (ra->head->index > up)
				perform_action(ra, rb, RA);
			perform_action(ra, rb, PB);
			if (rb->head && (rb->head->index < ((lo + up) / 2)))
				perform_action(ra, rb, RB);
			if (ra->size == 3 || ra->size == 4 || ra->size == 5)
				return ;
		}
	}
}

/* Give a score to each element of the stack. Lower is better. */
static void give_score(t_register *ra, t_register *rb)
{
	int     i;
	int     med;
	t_node *p;

	i = 1;
	p = rb->head;
	med = (rb->size + (rb->size % 2 == 1)) / 2;
	while (p)
	{
		if (i <= med)
		{
			p->score = i + (ra->head->index - p->index);
			if (ra->tail->index != ra->topi)
				p->score += 10 * (ra->tail->index - p->index);
		}
		else if (i > med)
		{
			p->score = ((rb->size - i) + 2) + (ra->head->index - p->index);
			if (ra->tail->index != ra->topi)
				p->score += 10 * (ra->tail->index - p->index);
		}
		i++;
		p = p->next;
	}
}

/*
** TODO Keep B balanced (centered), so that the score at each end are in
** the same range.
*/
static void merge(t_register *ra, t_register *rb)
{
	while (rb->size)
	{
		while (find_gap(ra))
			perform_action(ra, rb, RA);
		give_score(ra, rb);
		to_top(ra, rb, locate_index(rb, find_low_score(rb)), B);
		perform_action(ra, rb, PA);
		while (ra->head->index > ra->tail->index)
			perform_action(ra, rb, RRA);
	}
}

static void solve_large(t_register *ra, t_register *rb)
{
	push_slice(ra, rb);
	solve_small(ra, rb);
	merge(ra, rb);
}

void	solve(t_register *ra, t_register *rb)
{
	if (ra->size <= 5)
		return (solve_small(ra, rb));
	else
		return (solve_large(ra, rb));
}
