/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:05:57 by mbarberi          #+#    #+#             */
/*   Updated: 2022/12/15 17:56:52 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hasduplicates(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] == s[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_valid_base(char *base)
{
	if (!base[0] || !base[1])
		return (0);
	if (ft_hasduplicates(base))
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		base++;
	}
	return (1);
}

char	*ft_itoa_base(intmax_t n, char *base)
{
	char	*p;
	size_t	i;
	size_t	bl;
	int		size;

	if (!ft_valid_base(base))
		return (NULL);
	i = 0;
	bl = ft_strlen(base);
	size = ft_ndigit(n, ft_strlen(base));
	p = malloc(size + 1);
	if (!p)
		return (NULL);
	p[size] = '\0';
	if (n < 0)
		p[0] = '-';
	else if (!n)
		p[0] = '0';
	n = ft_abs(n);
	while (n)
	{
		p[--size] = base[n % bl];
		n /= bl;
	}
	return (p);
}
