/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:55:24 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/16 13:57:59 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if the given string represents an int.
 * @param s The string to check.
 * @return 1 if the string represents an int, else returns 0.
 */
int	ft_isint(const char *s)
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
