/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:16 by mbarberi          #+#    #+#             */
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
 * @brief The isupper(3) function tests for any upper-case letters.
 * @param c The character to test.
 * @return Zero if the character tests false, non-zero if the character
 * tests true.
 */
static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/**
 * @brief The isalpha(3) function tests for any character for which
 * isupper(3) or islower(3) is true.
 * @param c The character to test.
 * @return Zero if the character tests false, non-zero if the character
 * tests true.
 */
int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
