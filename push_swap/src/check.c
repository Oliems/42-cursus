/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:45:08 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/23 18:06:18 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	strcmp(const char *l, const char *r)
{
	while (*l == *r && *l)
	{
		l++;
		r++;
	}
	return (*(unsigned char *)l - *(unsigned char *)r);
}

/* Return 1 if INT_MIN < n < INT_MAX, else return 0. */
static int	ft_isint(const char *s)
{
	int64_t	tmp;

	tmp = ft_atoi(s);
	return (tmp >= INT_MIN && tmp <= INT_MAX);
}

/* Return 1 if the string represents a number, 0 if it does not. */
/* if (!*s) return (0); allows us to catch strings containing only - or + */
static int	ft_isnumber(const char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (ft_isdigit(*s))
		s++;
	if (!*s)
		return (1);
	else
		return (0);
}

static int	ft_hasduplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Check if the arguments provided are valid. Return 1 if an error occured */
int	check_arguments(int argc, char **argv)
{
	if (ft_hasduplicates(argc, argv))
		return (1);
	while (--argc > 0)
	{
		if (!ft_isnumber(argv[argc]))
			return (1);
		if (!ft_isint(argv[argc]))
			return (1);
	}
	return (0);
}
