/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:06:44 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:22:14 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return The last node of the list
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*p;

	p = lst;
	while (p)
	{
		if (!(p->next))
			return (p);
		p = p->next;
	}
	return (NULL);
}
