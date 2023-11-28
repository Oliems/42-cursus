/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:06:46 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:22:14 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the
 * content of each node. Creates a new list resulting of the successive
 * applications of the function 'f'. The 'del' function is used to delete
 * the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a
 * node if needed.
 * @return The new list or NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;
	t_list	*new;

	head = lst;
	new = NULL;
	while (head)
	{
		tmp = ft_lstnew((f)((void *)head->content));
		if (!tmp)
		{
			(del)(head->content);
			ft_lstclear(&new, del);
			break ;
		}
		head = head->next;
		ft_lstadd_back(&new, tmp);
	}
	return (new);
}
