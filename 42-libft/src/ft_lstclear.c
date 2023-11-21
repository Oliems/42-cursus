/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:06:35 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:22:14 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node and every successor of that
 * node, using the function 'del' and free(3). Finally, the pointer to the
 * list must be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the
 * node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		(del)((void *)(tmp->content));
		tmp->content = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
	}
	*lst = NULL;
}
