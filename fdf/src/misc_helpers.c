/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:54:29 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/15 11:52:04 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/**
 * @brief Print the error message corresponding to the error code.
 * @param err The error code.
 */
void	print_error(int err)
{
	if (err == ERR_CHAR)
		f_perror("The file contains illegal character(s).\n");
	else if (err == ERR_EMPTY)
		f_perror("The file is empty or the map is too small.\n");
	else if (err == ERR_LENGTH)
		f_perror("The map does not have the same number of elements \
on each line or the map does not end with a newline.\n");
	else if (err == ERR_FILE)
		f_perror("File does not exist or could not be opened.\n");
	else if (err == ERR_TRAIL_SPC)
		f_perror("The map contains trailing or consecutive whitespace(s).\n");
	else if (err == ERR_COLOR)
		f_perror("The map contains improperly formated hexdecimal colors.\n");
}

/**
 * @brief If a pointer has been set, free it. This functin is used by
 * fdf_init() in case an error occured.
 * @param env Structure containing informations about the program's
 * environment.
 */
void	fdf_free_if(t_fdf *env)
{
	if (env->win)
		mlx_destroy_window(env->mlx, env->win);
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if (env->m)
		matrix_destroy(env->m, env->ymap);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	env->win = NULL;
	env->img = NULL;
	env->addr = NULL;
	env->m = NULL;
	env->mlx = NULL;
	free(env);
	env = NULL;
}
