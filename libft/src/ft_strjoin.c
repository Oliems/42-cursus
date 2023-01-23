/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:15 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/15 16:40:53 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne une nouvelle chaîne, résultat de la
** concaténation de s1 et s2.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	p = malloc(l1 + l2 + 1);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1, l1 + 1);
	p += l1;
	ft_strlcpy(p, s2, l2 + 1);
	return (p - l1);
}
