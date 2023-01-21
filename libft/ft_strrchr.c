/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:40 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/07 17:17:09 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strrchr() function locates the last occurrence of c (converted to a
** char) in the string s.  If c is `\0', strrchr() locates the terminating
** `\0'.
*/
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	while (i--)
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
	return (NULL);
}
