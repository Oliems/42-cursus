/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:28:25 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/07 16:42:46 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applique la fonction 'f' à chaque caractère de la chaîne de caractères
** transmise comme argument, et en passant son index comme premier argument.
** Chaque caractère est transmis par adresse à 'f' afin d'être modifié si
** nécessaire.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*p;

	if (!s || !f)
		return ;
	p = s;
	while (*p)
	{
		f((unsigned int)(p - s), p);
		p++;
	}
}
