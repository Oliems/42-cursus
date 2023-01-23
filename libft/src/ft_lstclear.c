/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:06:35 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/07 16:42:46 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Supprime et libère la mémoire de l'élément passé en paramètre, et de tous
** les éléments qui suivent, à l'aide de 'del' et de free(3). Enfin, le
** pointeur initial doit être mis à NULL.
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
