/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:57:10 by mbarberi          #+#    #+#             */
/*   Updated: 2022/11/14 14:40:51 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcmp() function compares byte string b1 against byte string b2.
** Both strings are assumed to be len bytes long.
*/
int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)b1;
	p2 = (unsigned char *)b2;
	while (len--)
		if (*p1++ != *p2++)
			return ((*(p1 - 1) - *(p2 - 1)));
	return (0);
}
