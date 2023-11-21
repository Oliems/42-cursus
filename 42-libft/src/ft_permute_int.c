/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permute_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:57:31 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/12 17:38:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is based on Algorithm L by Donald Knuth. Given an
** array of integers already sorted in increasing order, modify the
** array in place to generate the next permutation in lexicographical
** order. The parameter n is the number of elements in the array. If a
** permutation exists the function returns 1, if not it returns 0.
*/

static void	ft_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	ft_permute_int(int *arr, int n)
{
	int	k;
	int	l;
	int	lo;
	int	hi;

	k = n - 2;
	while (k >= 0 && arr[k] > arr[k + 1])
		k--;
	if (k < 0)
		return (0);
	l = n - 1;
	while (arr[k] > arr[l])
		l--;
	ft_swap(&arr[k], &arr[l]);
	lo = k + 1;
	hi = n - 1;
	while (lo < hi)
	{
		ft_swap(&arr[lo], &arr[hi]);
		lo++;
		hi--;
	}
	return (1);
}
