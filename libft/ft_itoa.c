/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:56:32 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/15 17:39:34 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Using malloc(3), allocate enough memory to store a string representing `n'
** and return a pointer to the string.
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
