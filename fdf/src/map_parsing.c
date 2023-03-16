/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:46:40 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/15 07:55:09 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Extract the hexadecimal part of a string of the form 'int,hex'.
 * @param s The string to process.
 * @param l The length of 's'.
 * @return The hexadecimal value converted to unsigned int if one was
 * found, else returns 0xFFFFFF (i.e white in RGB).
 */
static int	map_extract_color(char *s, int l)
{
	s = f_memchr(s, ',', l);
	if (!s)
		return (WHITE);
	return (hex2int(s + 3));
}

/**
 * @brief For each t_point in the matrix, fill in the x, y, z and color members.
 * @param m The matrix.
 * @param map The string representing the map.
 * @param w The number of columns in the matrix.
 * @param h The number of rows in the matrix.
 */
static void	matrix_fill(t_matrix m, char *map, int w, int h)
{
	int		i;
	int		j;
	int		l;
	char	*p;

	j = 0;
	l = f_strlen(map);
	p = map_split(map);
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			m[j][i].x = i;
			m[j][i].y = j;
			m[j][i].z = f_atoi(p);
			m[j][i].color = map_extract_color(p, f_strlen(p));
			p = f_memchr(p, '\0', l - (p - map));
			p++;
			i++;
		}
		j++;
	}
}

/**
 * @brief For each t_point in the matrix, compute the isometric coordinates
 * for each point.
 * @param m The matrix.
 * @param w The number of columns in the matrix.
 * @param h The number of rows in the matrix.
 */
static void	matrix_fill_iso(t_matrix m, int w, int h)
{
	int	i;
	int	j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			m[j][i].u = (m[j][i].x - m[j][i].y) * COS_ANGLE;
			m[j][i].v = (m[j][i].x + m[j][i].y) * SIN_ANGLE - m[j][i].z;
			i++;
		}
		j++;
	}
}

/**
 * @brief Transform the map contained in the array map into a 2D array of
 * t_point.
 * @param map The string representing the map.
 * @param w The number of columns in the matrix.
 * @param h The number of rows in the matrix.
 * @param l The length of The string representing the map.
 * @return A 2D array of type t_matrix or NULL if an error occured.
 */
t_matrix	map_to_matrix(char *map, int w, int h)
{
	t_matrix	m;

	if (!map || w < 1 || h < 1)
		return (NULL);
	m = matrix_create(w, h);
	if (!m)
		return (NULL);
	matrix_fill(m, map, w, h);
	matrix_fill_iso(m, w, h);
	return (m);
}
