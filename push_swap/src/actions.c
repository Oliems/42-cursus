/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:44:39 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/23 18:06:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** Push the first element of s onto d.
** pa => s = B and d = A.
** pb => s = A and d = B.
 */
static void	push(t_register *d, t_register *s)
{
	t_node	*arr[3];

	if (!s || !d || !(s->size))
		return ;
	arr[0] = s->head;
	arr[1] = s->head->next;
	arr[2] = d->head;
	s->size--;
	d->size++;
	s->head = arr[1];
	d->head = arr[0];
	if (s->size <= 1)
		s->tail = arr[1];
	if (d->size <= 1)
		d->tail = arr[0];
	arr[0]->next = arr[2];
	if (arr[1])
		arr[1]->prev = NULL;
	if (arr[2])
		arr[2]->prev = arr[0];
}

/*
** Shift all elements up (left). The first element becomes the last one.
** [A]-[B]-[C]-[D] => [B]-[C]-[D]-[A]
**  0   1   2   3      1   2   3   0
*/
static void	rot(t_register *r)
{
	t_node	*arr[4];

	if (!r || r->size < 2)
		return ;
	arr[0] = r->head;
	arr[1] = r->head->next;
	arr[2] = r->tail->prev;
	arr[3] = r->tail;
	arr[1]->prev = NULL;
	arr[3]->next = arr[0];
	arr[0]->prev = arr[3];
	arr[0]->next = NULL;
	r->head = arr[1];
	r->tail = arr[0];
}

/*
** Shift all elements down (right). The last element becomes the first one.
** [A]-[B]-[C]-[D] => [D]-[A]-[B]-[C]
**  0   1   2   3      3   0   1   2
*/
static void	rev(t_register *r)
{
	t_node	*arr[4];

	if (!r || r->size < 2)
		return ;
	arr[0] = r->head;
	arr[1] = r->head->next;
	arr[2] = r->tail->prev;
	arr[3] = r->tail;
	arr[0]->prev = arr[3];
	arr[2]->next = NULL;
	arr[3]->prev = NULL;
	arr[3]->next = arr[0];
	r->head = arr[3];
	r->tail = arr[2];
}

/*
** Swap the first two elements of the stack.
** [A]-[B]-[C]-[D] => [B]-[A]-[C]-[D]
**  0   1   2   3      1   0   2   3
*/
static void	swap(t_register *r)
{
	t_node	*arr[3];

	if (!r || r->size < 2)
		return ;
	if (r->size == 2)
		return (rot(r));
	arr[0] = r->head;
	arr[1] = r->head->next;
	arr[2] = r->head->next->next;
	arr[0]->prev = arr[1];
	arr[0]->next = arr[2];
	arr[1]->prev = NULL;
	arr[1]->next = arr[0];
	arr[2]->prev = arr[0];
	r->head = arr[1];
}

void	perform_action(t_register *a, t_register *b, int action)
{
	if (action == SA)
		return (write(1, "sa\n", 3), swap(a));
	else if (action == SB)
		return (write(1, "sb\n", 3), swap(b));
	else if (action == SS)
		return (write(1, "ss\n", 3), swap(a), swap(b));
	else if (action == PA)
		return (write(1, "pa\n", 3), push(a, b));
	else if (action == PB)
		return (write(1, "pb\n", 3), push(b, a));
	else if (action == RA)
		return (write(1, "ra\n", 3), rot(a));
	else if (action == RB)
		return (write(1, "rb\n", 3), rot(b));
	else if (action == RR)
		return (write(1, "rr\n", 3), rot(a), rot(b));
	else if (action == RRA)
		return (write(1, "rra\n", 4), rev(a));
	else if (action == RRB)
		return (write(1, "rrb\n", 4), rev(b));
	else if (action == RRR)
		return (write(1, "rrr\n", 4), rev(a), rev(b));
}
