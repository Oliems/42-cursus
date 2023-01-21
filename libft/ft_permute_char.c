/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permute_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:57:23 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/12 18:21:28 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is based on Algorithm L by Donald Knuth. Given an
** array of characters already sorted in increasing order, modify the
** array in place to generate the next permutation in lexicographical
** order. The parameter n is the number of elements in the array. If a
** permutation exists the function returns 1, if not it returns 0.
*/
static void	ft_swap(void *i, void *j)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	tmp;

	a = (unsigned char *)i;
	b = (unsigned char *)j;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_permute(void *b, int n)
{
	int				k;
	int				l;
	int				lo;
	int				hi;
	unsigned char	*p;

	k = n - 2;
	p = (unsigned char *)b;
	while (k >= 0 && p[k] > p[k + 1])
		k--;
	if (k < 0)
		return (0);
	l = n - 1;
	while (p[k] > p[l])
		l--;
	ft_swap(&p[k], &p[l]);
	lo = k + 1;
	hi = n - 1;
	while (lo < hi)
		ft_swap(&p[lo++], &p[hi--]);
	return (1);
}
