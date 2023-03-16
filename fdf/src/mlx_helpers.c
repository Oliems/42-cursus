/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:35:54 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/15 11:43:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/X.h> 			/* event masks */
#include <X11/keysym.h>		/* keycodes */

int	fdf_exit(t_fdf *env)
{
	mlx_loop_end(env->mlx);
	mlx_destroy_image(env->mlx, env->img);
	env->img = NULL;
	mlx_destroy_window(env->mlx, env->win);
	env->win = NULL;
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	env->mlx = NULL;
	matrix_destroy(env->m, env->ymap);
	free(env);
	env = NULL;
	exit(EXIT_SUCCESS);
}

int	fdf_hook_keypress(int key, t_fdf *env)
{
	if (key == XK_Escape)
		fdf_exit(env);
	return (0);
}

void	fdf_setup_hooks(t_fdf *env)
{
	mlx_key_hook(env->win, fdf_hook_keypress, env);
	mlx_hook(env->win, DestroyNotify, NoEventMask, fdf_exit, env);
	mlx_hook(env->win, Expose, ExposureMask, map_draw, env);
}
