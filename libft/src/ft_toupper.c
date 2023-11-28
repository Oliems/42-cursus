/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:56 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:21:54 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The islower(3) function tests for any lower-case letters.
 * @param c The character to test.
 * @return Zero if the character tests false, non-zero if the character
 * tests true.
 */
static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * @brief The toupper(3) function converts a lower-case letter to the
 * corresponding upper-case letter.
 * @param c The character to convert.
 * @return The corresponding upper-case letter if there is one; otherwise,
 * the argument is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	else
		return (c);
}
