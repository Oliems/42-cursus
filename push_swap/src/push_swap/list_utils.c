/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:01:34 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/19 12:47:17 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* Create a new node. */
t_node	*new_node(int n, int index)
{
	t_node	*p;

	p = malloc(sizeof(t_node));
	if (!p)
		return (NULL);
	p->data = n;
	p->index = index;
	p->score = 0;
	p->next = NULL;
	p->prev = NULL;
	return (p);
}

/* Add a node to the back of the list and update the register. */
void	add_node(t_register *r, t_node *new)
{
	if (!r || !new)
		return ;
	if (!(r->head) && !(r->tail))
	{
		r->head = new;
		r->tail = new;
		return ;
	}
	r->tail->next = new;
	new->prev = r->tail;
	r->tail = new;
}

/* Free the linked list and the register. */
void	free_all(t_register *r)
{
	t_node	*curr;
	t_node	*next;

	if (!r->head || !r)
		return ;
	curr = r->head;
	while (curr)
	{
		next = curr->next;
		curr->next = NULL;
		curr->prev = NULL;
		free(curr);
		curr = next;
	}
	r->head = NULL;
	r->tail = NULL;
	free(r);
}

/* Check if the stack is sorted. Return 1 if it is. */
int	is_sorted(t_register *r)
{
	t_node *k;
	t_node *l;

	k = r->head;
	l = r->head->next;
	while (k && l)
	{
		if (k->index > l->index)
			return (0);
		k = k->next;
		l = l->next;
	}
	return (1);
}
