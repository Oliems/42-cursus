/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:04:05 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/22 17:35:07 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Write a pixel on an mlx image.
 * @param env Structure containing information about the program's
 * environment.
 * @param x The x coordinate of the pixel.
 * @param y The y coordinate of the pixel.
 * @param color The color coordinate of the pixel.
 */
static void	mlx_pixel_put_img(t_fdf *env, int x, int y, int color)
{
	char	*dst;

	dst = env->addr + (y * env->llen + x * (env->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief Linearly interpolate two colors.
 * @param c1 The color of the first point.
 * @param c2 The color of the second point.
 * @param t Value between 0 and 1 which moves along the segment that
 * connect the two points.
 * @return The color to be used at the given time/position t.
 */
static uint32_t	lerp(uint32_t c1, uint32_t c2, double t)
{
	uint8_t		a;
	uint8_t		b;
	uint8_t		c;
	uint32_t	r;

	r = 0;
	a = (c1 >> 16) & 0xFF;
	b = (c2 >> 16) & 0xFF;
	c = a + (b - a) * t;
	r |= c;
	r <<= 8;
	a = (c1 >> 8) & 0xFF;
	b = (c2 >> 8) & 0xFF;
	c = a + (b - a) * t;
	r |= c;
	r <<= 8;
	a = c1 & 0xFF;
	b = c2 & 0xFF;
	c = a + (b - a) * t;
	r |= c;
	return (r);
}

/**
 * @brief Draw a line between two points using Bresenham's algorithm.
 * @param a Starting point.
 * @param b Destination point.
 * @param env Structure containing information about the program's
 * environment.
 */
static void	draw_line(t_point a, t_point b, t_fdf *env)
{
	double	t;
	double	max;
	double	step_x;
	double	step_y;
	double	step_rgb;

	t = 0;
	step_x = b.u - a.u;
	step_y = b.v - a.v;
	max = fmax(fabs(step_x), fabs(step_y));
	step_x /= max;
	step_y /= max;
	step_rgb = 1 / max;
	while ((int)(a.u - b.u) || (int)(a.v - b.v))
	{
		mlx_pixel_put_img(env, a.u, a.v, lerp(a.color, b.color, t));
		a.u += step_x;
		a.v += step_y;
		t += step_rgb;
		if (a.u > env->xwin || a.v > env->ywin || a.v < 0 || a.u < 0)
			break ;
	}
}

/**
 * @brief Draw the map by drawing a line between each point and the one to
 * its right and the one below.
 * @param env Structure containing information about the program's
 * environment.
 */
int	map_draw(t_fdf *env)
{
	int		y;
	int		x;

	y = 0;
	while (y < env->ymap)
	{
		x = 0;
		while (x < env->xmap)
		{
			if (y + 1 < env->ymap)
				draw_line(env->m[y][x], env->m[y + 1][x], env);
			if (x + 1 < env->xmap)
				draw_line(env->m[y][x], env->m[y][x + 1], env);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}
