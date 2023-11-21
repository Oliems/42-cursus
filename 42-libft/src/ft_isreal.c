/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isreal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:05:57 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/16 14:22:06 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if the given string represents a real number.
 * @param s The string to check.
 * @return 1 if the string represents a real number, else returns 0.
 * Strings of form "123.", ".", 123.45.67" a
 */
int	ft_isreal(const char *s)
{
	int	dot;

	dot = 0;
	if (s[0] == '.' && !ft_isdigit(s[1]))
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (!*s)
		return (0);
	while (ft_isdigit(*s) || *s == '.')
	{
		if (*s == '.' && !ft_isdigit(*(s + 1)))
			return (0);
		else if (*s == '.' && dot)
			return (0);
		else if (*s == '.' && !dot)
			dot = 1;
		s++;
	}
	if (!*s && dot)
		return (1);
	else
		return (0);
}
