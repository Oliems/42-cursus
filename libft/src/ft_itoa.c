/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:56:32 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:22:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compute the absolute value of the integer n.
 * @param n The number we want to compute.
 * @return An unsigned integer to ensure that we can compute abs(INT_MIN).
 */
static uintmax_t	ft_abs(intmax_t n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

/*
** Compute the number of digits an integer will have in a given base, including
** the minus sign if n < 0.
*/
static int	ft_ndigit(int n, int baselen)
{
	int	l;

	l = 0;
	if (n <= 0)
		l += 1;
	while (n)
	{
		l++;
		n /= baselen;
	}
	return (l);
}

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument. Negative numbers must be handled.
 * @param n The integer to convert.
 * @return The string representing the integer or NULL if the allocation
 * fails.
 */
char	*ft_itoa(int n)
{
	int		l;
	size_t	nb;
	char	*s;

	l = ft_ndigit(n, 10);
	s = malloc(l + 1);
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n < 0)
		s[0] = '-';
	else if (!n)
		s[0] = '0';
	nb = ft_abs(n);
	while (nb)
	{
		s[--l] = nb % 10 + '0';
		nb /= 10;
	}
	return (s);
}
