/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:20:30 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/14 09:42:27 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Check if a character is part of the set of legal characters.
 * @param c The character to check.
 * @return Returns 1 if the character is part of the set, else returns 0.
 */
int	is_char_legal(int c)
{
	return ((c >= '0' && c <= '9') || c == 'x' || c == ',' || c == ' '
		|| c == '\n' || c == '-' || (c >= 'A' && c <= 'F')
		|| (c >= 'a' && c <= 'f'));
}

/**
 * @brief Compute the width of the map, i.e the number of words in a line.
 * @param map The string representing the map.
 * @return The number of elements in a line, or -1 if map is a NULL pointer
 * or if the map starts with a space (this is also checked by
 * map_exists()).
 */
int	map_get_width(const char *s)
{
	int	n;
	int	inword;

	n = 0;
	inword = 0;
	if (!s || s[0] == ' ')
		return (-1);
	while (*s && *s != '\n')
	{
		if (*s != ' ')
		{
			if (!inword)
			{
				inword = 1;
				n++;
			}
		}
		else if (inword)
			inword = 0;
		s++;
	}
	return (n);
}

/**
 * @brief Compute the height of the map, i.e the number of lines.
 * @param map The string representing the map.
 * @return The height or -1 if an error occured. This functions expects the
 * last line to end with '\n' thus the `return (i - 1)`.
 */
int	map_get_height(const char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	while (map && *map)
	{
		if (*map == '\n')
			i++;
		map++;
	}
	return (i);
}
