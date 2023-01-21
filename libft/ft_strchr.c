/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:04 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/09 13:42:14 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strchr() and strchrnul() functions locate the first occurrence of c
** in the string pointed to by s.  The terminating NUL character is consid-
** ered part of the string.  If c is `\0', strchr() and strchrnul() locate
** the terminating `\0'.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (NULL);
	return ((char *)s);
}
