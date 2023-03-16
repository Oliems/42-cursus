/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:36:22 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/15 12:01:42 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * FdF map format rules:
 * - The map must contain only the following characters: [0-9], [A-F],
 *   [a-f], ' ', '-', '\n', 'x' and ','.
 * - The map must end with a newline.
 * - The map must not have trailing whitespaces.
 * - All the lines in the map must have the same number of elements.
 * - Format : (-)[0-9](','[0-9 || A-F])' '.
*/

/**
 * @brief Check if all the lines have the same number of elements.
 * @param map The string representing the map.
 * @return True if all the lines have the same number of elements, else
 * returns false.
 */
static bool	map_has_equal_lines(char *map)
{
	int		l;
	int		maplen;
	char	*p;

	l = map_get_width(map);
	maplen = f_strlen(map);
	p = f_memchr(map, '\n', maplen);
	while (1)
	{
		p = f_memchr(p, '\n', maplen - (p - map));
		if (!p)
			return (false);
		p += 1;
		if (!*p)
			break ;
		if (map_get_width(p) != l)
			return (false);
	}
	return (true);
}

/**
 * @brief Check if the map contains illegal characters.
 * @param map The string representing the map.
 * @return True if the map contains illegal characters, else returns false.
 */
static bool	map_has_illegal_char(char *map)
{
	while (*map)
	{
		if (!is_char_legal(*map))
			return (true);
		map++;
	}
	return (false);
}

/**
 * @brief Check Check if the map contains consecutive or trailing
 * whitespaces.
 * @param map The string representing the map.
 * @return True if the string contains consecutive whitespace, else returns
 * false.
 */
static bool	map_has_consecutive_whitespace(char *map)
{
	while (*map)
	{
		if (*map == ' ' && *(map + 1) == ' ')
			return (true);
		else if (*map == ' ' && *(map + 1) == '\n')
			return (true);
		else if (*map == '\n' && *(map + 1) == ' ')
			return (true);
		else if (*map == '\n' && *(map + 1) == '\n')
			return (true);
		map++;
	}
	return (false);
}

/**
 * @brief Check if the characters after a ',' form a valid hexadecimal
 * color i.e are at least  "0x[0-9][A-F][a-f]".
 * @param map The string representing the map.
 * @return True if one of the color is not properly formated, else returns
 * false.
 */
static bool	map_has_invalid_color(char *map)
{
	while (*map)
	{
		if (*map == ',')
			if (!(*(map + 1) == '0'
					&& *(map + 2) == 'x' && f_isalnum(*(map + 3))))
				return (true);
		map++;
	}
	return (false);
}

/**
 * @brief Check if the map contained in the file is legal.
 * @param map The string representing the map.
 * @return True if the map is valid, false if it is not.
 */
bool	is_map_valid(char *map)
{
	if (!*map || *map == '\n'
		|| map_get_width(map) < 0 || map_get_height(map) < 0)
		return (print_error(ERR_EMPTY), false);
	if (map_has_illegal_char(map))
		return (print_error(ERR_CHAR), false);
	if (!map_has_equal_lines(map))
		return (print_error(ERR_LENGTH), false);
	if (map_has_consecutive_whitespace(map))
		return (print_error(ERR_TRAIL_SPC), false);
	if (map_has_invalid_color(map))
		return (print_error(ERR_COLOR), false);
	return (true);
}
