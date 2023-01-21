/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:32 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/09 13:39:35 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strncmp() function lexicographically compare the nul-terminated strings
** s1 and s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	if (!len)
		return (0);
	while (1)
	{
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (!*s1++)
			break ;
		if (!--len)
			break ;
	}
	return (0);
}
