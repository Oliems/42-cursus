/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:57:14 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/12 17:19:03 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcpy() function copies len bytes from string src to string dst.
** The arguments must not overlap -- behavior if the arguments overlap is
** undefined.
*/
void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	void	*d;

	d = dst;
	if (!dst && !src)
		return (NULL);
	while (len--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (d);
}
