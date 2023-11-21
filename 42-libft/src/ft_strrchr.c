/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:01:40 by mbarberi          #+#    #+#             */
/*   Updated: 2023/02/03 18:22:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strrchr() function locates the last occurrence of c
 * (converted to a char) in the string pointed to by s.  The terminating
 * null character is considered to be part of the string; therefore if c is
 * ‘\0’, the functions locate the terminating ‘\0’.
 * @param s The string to search.
 * @param c The character to find.
 * @return A pointer to the located character, or NULL if the character
 * does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c)
{
	return (ft_memrchr(s, c, ft_strlen(s) + 1));
}
