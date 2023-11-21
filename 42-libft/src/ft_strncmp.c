/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:32 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:51:24 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strncmp(3) function lexicographically compares the
 * null-terminated strings s1 and s2. strncmp() compares not more than n
 * characters. Because strncmp() is designed for comparing strings rather
 * than binary data, characters that appear after a ‘\0’ character are not
 * compared.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n The maximum number of characters to compare.
 * @return An integer greater than, equal to, or less than 0, according as
 * the string s1 is greater than, equal to, or less than the string s2. The
 * comparison is done using unsigned characters, so that ‘\200’ is greater
 * than ‘\0’.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (!n--)
		return (0);
	while (*p1 && *p2 && n && *p1 == *p2)
	{
		p1++;
		p2++;
		n--;
	}
	return (*p1 - *p2);
}
