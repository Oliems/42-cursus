/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:19 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/06 17:51:55 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strnlen(3) function attempts to compute the length of s, but
 * never scans beyond the first n bytes of s.
 * @param s A string.
 * @param n The maximum number of bytes to scan.
 * @return Either the same result as strlen(3) or n, whichever is smaller.
 */
static size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*p;

	p = ft_memchr(s, 0, n);
	if (p)
		return (p - s);
	return (n);
}

/**
 * @brief The strlcat(3) function appends the NUL-terminated string s to
 * the end of d. It will append at most n - strlen(d) - 1 bytes,
 * NUL-terminating the result. d and s must not overlap.
 * @param d The destination.
 * @param s The source.
 * @param n The destination's size.
 * @return The total length of the string the function tried to create.
 * That means the initial length of d plus the length of s.
 */
size_t	ft_strlcat(char *d, const char *s, size_t n)
{
	size_t	l;

	l = ft_strnlen(d, n);
	if (l == n)
		return (l + ft_strlen(s));
	return (l + ft_strlcpy(d + l, s, n - l));
}
