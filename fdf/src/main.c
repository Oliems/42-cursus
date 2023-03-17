/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:38:16 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/17 11:19:47 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	char	*map;
	t_fdf	*env;

	if (argc != 2)
		return (f_perror("Usage: ./fdf <map.fdf>\n"), EXIT_SUCCESS);
	map = f_file_to_array(argv[1]);
	if (!map)
		return (print_error(ERR_FILE), EXIT_SUCCESS);
	if (!is_map_valid(map))
		return (free(map), EXIT_SUCCESS);
	env = fdf_init(map);
	free(map);
	if (!env)
		return (EXIT_FAILURE);
	fdf_setup_hooks(env);
	map_draw(env);
	mlx_loop(env->mlx);
	return (0);
}
