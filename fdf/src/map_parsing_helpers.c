/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:44:53 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/14 11:47:53 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief For each struct in the matrix, set all members to a default value.
 * @param m The matrix.
 * @param w The number of columns in the matrix.
 * @param h The number of rows in the matrix.
 */
static void	matrix_init(t_matrix m, int w, int h)
{
	int		i;
	int		j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			m[j][i].x = 0;
			m[j][i].y = 0;
			m[j][i].z = 0;
			m[j][i].u = 0;
			m[j][i].v = 0;
			m[j][i].color = WHITE;
			i++;
		}
		j++;
	}
}

/**
 * @brief Free the matrix.
 * @param m The matrix.
 * @param h The number of rows in the matrix.
 */
void	matrix_destroy(t_matrix m, int h)
{
	int	i;

	i = 0;
	if (!m)
		return ;
	while (i < h)
	{
		free(m[i]);
		m[i++] = NULL;
	}
	free(m);
	m = NULL;
}

/**
 * @brief Create a matrix (i.e a two-dimensional array) of t_point.
 * @param w The number of columns in the matrix.
 * @param h The number of rows in the matrix.
 * @return The matrix or NULL if an error occured.
 */
t_matrix	matrix_create(int w, int h)
{
	int			i;
	t_matrix	m;

	i = 0;
	m = malloc(h * sizeof(t_point *));
	if (!m)
		return (NULL);
	while (i < h)
	{
		m[i] = malloc(w * sizeof(t_point));
		if (!m[i])
			return (matrix_destroy(m, i), NULL);
		i++;
	}
	matrix_init(m, w, h);
	return (m);
}

/**
 * @brief Replace all ' ' and '\n' with '\0'.
 * @param map The string representing the map.
 * @return A pointer to the first character in map.
 */
char	*map_split(char *map)
{
	char	*p;

	p = map;
	while (*p)
	{
		if (*p == ' ' || *p == '\n')
			*p = '\0';
		p++;
	}
	return (map);
}

/**
 * @brief Convert a string representing an hexadecimal number to an
 * unsigned int.
 * @param hex The string representing the hexadecimal number.
 * @return An unsigned int corresponding to 'hex'.
 */
uint32_t	hex2int(char *hex)
{
	uint8_t		byte;
	uint32_t	val;

	val = 0;
	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}
