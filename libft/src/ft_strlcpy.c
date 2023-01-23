/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:22 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/09 14:31:52 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcpy() function copies up to size - 1 characters from the
** NUL-terminated string src to dst, NUL-terminating the result.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int			l;

	l = ft_strlen(src);
	if (!dstsize)
		return (l);
	dstsize -= 1;
	while (dstsize-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (l);
}
