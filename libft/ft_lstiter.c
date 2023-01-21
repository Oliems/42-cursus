/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:06:42 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/07 16:42:46 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Itère sur la liste 'lst' et applique la fonction 'f' au contenu chaque
** élément.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*p;

	p = lst;
	while (p)
	{
		(f)((void *)p->content);
		p = p->next;
	}
}
