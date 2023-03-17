/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:38:19 by mbarberi          #+#    #+#             */
/*   Updated: 2023/03/17 11:18:49 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "mlc.h"
# include <math.h>			/* fabs(3), fmax(3) */
# include <stdlib.h> 		/* malloc(3) */
# include <stdbool.h>		/* __Bool */

# define WINW 1000
# define WINH 1000
# define WHITE 0xFFFFFF
# define COS_ANGLE 0.86602540378f /* cos(30 * M_PI / 180.0) */
# define SIN_ANGLE 0.49999999999f /* sin(30 * M_PI / 180.0) */

typedef struct s_fdf	t_fdf;
typedef struct s_point	t_point;
typedef t_point			**t_matrix;

struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			llen;
	int			end;
	int			xwin;
	int			ywin;
	int			xmap;
	int			ymap;
	double		xoff;
	double		yoff;
	double		scale;
	t_matrix	m;
};

struct s_point
{
	int			x;
	int			y;
	int			z;
	uint32_t	color;
	double		u;
	double		v;
};

enum e_errors
{
	ERR_CHAR,
	ERR_EMPTY,
	ERR_LENGTH,
	ERR_FILE,
	ERR_TRAIL_SPC,
	ERR_COLOR
};

/* MAIN.C */

/* DRAW.C */
int			map_draw(t_fdf *env);

/* FDF_INIT.C */
t_fdf		*fdf_init(char *map);

/* MAP_CHECKING.C */
bool		is_map_valid(char *buf);

/* MAP_PARSING.C */
t_matrix	map_to_matrix(char *map, int w, int h);

/* MLX_HELPERS.C */
void		fdf_setup_hooks(t_fdf *env);
int			fdf_exit(t_fdf *env);
int			fdf_hook_keypress(int key, t_fdf *env);

/* MAP_CHECKING_HELPERS.C */
int			is_char_legal(int c);
int			map_get_width(const char *map);
int			map_get_height(const char *map);

/* MAP_PARSING_HELPERS.C */
char		*map_split(char *map);
uint32_t	hex2int(char *hex);
void		matrix_destroy(t_matrix m, int h);
t_matrix	matrix_create(int w, int h);

/* MISC_HELPERS.C */
void		print_error(int err);
void		fdf_free_if(t_fdf *env);

#endif
