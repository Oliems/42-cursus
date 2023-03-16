/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 07:31:37 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/15 08:00:34 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Initialize all members to a sane default value.
 * @param env Structure containing informations about the program's
 * environment.
 * @param map The string representing the map.
 */
static void	fdf_init_members(t_fdf *env, char *map)
{
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->addr = NULL;
	env->m = NULL;
	env->bpp = 0;
	env->llen = 0;
	env->end = 0;
	env->xwin = WINW;
	env->ywin = WINH;
	env->xmap = map_get_width(map);
	env->ymap = map_get_height(map);
	env->xoff = 0.0;
	env->yoff = 0.0;
	env->scale = 1.0;
}

/**
 * @brief Find the offset so that the top left corner lies on the top edge
 * of the screen and the bottom left corner lies on the left edge of the
 * screen.
 * @param env Structure containing informations about the program's
 * environment.
 */
static void	fdf_init_offset(t_fdf *env)
{
	int			i;
	int			j;
	t_point		tmp;

	j = 0;
	tmp.u = 0;
	tmp.v = 0;
	while (j < env->ymap)
	{
		i = 0;
		while (i < env->xmap)
		{
			if (env->m[j][i].u < tmp.u)
				tmp.u = env->m[j][i].u;
			if (env->m[j][i].v < tmp.v)
				tmp.v = env->m[j][i].v;
			i++;
		}
		j++;
	}
	env->xoff = fabs(tmp.u);
	env->yoff = fabs(tmp.v);
}

/**
 * @brief Find the scale factor so that the top and bottom rigth corners of
 * the map lie as close as possible to the right and bottom edges of the
 * screen, respectively.
 * @param env Structure containing informations about the program's
 * environment.
 */
static void	fdf_init_scale(t_fdf *env)
{
	int			i;
	int			j;
	t_point		tmp;

	j = 0;
	tmp.u = 0;
	tmp.v = 0;
	while (j < env->ymap)
	{
		i = 0;
		while (i < env->xmap)
		{
			if (env->m[j][i].u > tmp.u)
				tmp.u = env->m[j][i].u;
			if (env->m[j][i].v > tmp.v)
				tmp.v = env->m[j][i].v;
			i++;
		}
		j++;
	}
	while ((env->scale * (tmp.u + env->xoff) < env->xwin)
		&& (env->scale * (tmp.v + env->yoff) < env->ywin))
		env->scale += 0.5;
	if (env->scale >= 1.0)
		env->scale -= 0.5;
}

/**
 * @brief Multiply the offset the isometric coordinates of each point and
 * multiply by the scale so that the we do not have to do it in the
 * map_draw() function.
 * @param env Structure containing informations about the program's
 * environment.
 */
static void	fdf_init_view(t_fdf *env)
{
	int			i;
	int			j;

	j = 0;
	while (j < env->ymap)
	{
		i = 0;
		while (i < env->xmap)
		{
			env->m[j][i].u = env->scale * (env->m[j][i].u + env->xoff);
			env->m[j][i].v = env->scale * (env->m[j][i].v + env->yoff);
			i++;
		}
		j++;
	}
}

/**
 * @brief Initialize the mlx-related members and set the scale / offset for
 * each point in the matrix.
 * @param map The string representing the map.
 * @return The t_fdf structure containing all the informations we need to
 * draw the map and manage the window. If an error occured, everything
 * that was allocated up to that point is free'd and NULL is returned.
 */
t_fdf	*fdf_init(char *map)
{
	t_fdf	*p;

	p = malloc(sizeof(t_fdf));
	if (!p)
		return (NULL);
	fdf_init_members(p, map);
	p->mlx = mlx_init();
	if (!(p->mlx))
		return (free(p), NULL);
	p->win = mlx_new_window(p->mlx, p->xwin, p->ywin, "FdF");
	p->img = mlx_new_image(p->mlx, p->xwin, p->ywin);
	if (!(p->win) || !(p->img))
		return (fdf_free_if(p), NULL);
	p->addr = mlx_get_data_addr(p->img, &(p->bpp), &(p->llen), &(p->end));
	p->m = map_to_matrix(map, p->xmap, p->ymap);
	if (!(p->addr) || (!p->m))
		return (fdf_free_if(p), NULL);
	fdf_init_offset(p);
	fdf_init_scale(p);
	fdf_init_view(p);
	return (p);
}
