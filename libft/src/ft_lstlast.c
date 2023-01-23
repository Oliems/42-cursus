/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:06:44 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/15 14:48:27 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Renvoie le dernier élément de la liste. */
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
