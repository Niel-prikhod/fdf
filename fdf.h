/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:50:38 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/26 16:22:46 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <curses.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define ANGLE 30 * M_PI / 180

typedef struct s_points
{
	int			x_raw;
	int			y_raw;
	int			z_raw;
	int			color;
}				t_points;

typedef struct s_map
{
	int			height;
	int			width;
	t_points	**points;
}				t_map;

typedef struct s_view
{
	int			zoom;
	int			offset_x;
	int			offset_y;
	float		map_center_x;
	float		map_center_y;
	float		z_scale;
}				t_view;

typedef struct s_proj
{
	int			x_proj;
	int			y_proj;
	int			color;
}				t_proj;

typedef struct s_img
{
	void		*img_ptr;
	int			bpp;
	int			line_len;
	int			endian;
	void		*addr;
}				t_img;

typedef struct s_fdf
{
	void		*mlx;
	void		*window;
	t_map		*map;
	t_view		*view;
}				t_fdf;

// fdf_utils.c
void			fdf_clean_all(t_fdf *fdf);
t_fdf			*fdf_init(void);
t_img			*init_img(void *mlx, int width, int height);

// fdf_parser.c
bool			fdf_parser(const char *filename, t_map *map);

// fdf_file_handle.c
int				get_map_dimensions(const char *filename, t_map *map);
bool			check_args(int ac, char **av);

// fdf_math.c
void			set_def_view(t_fdf *fdf);
t_proj			apply_isometric(t_view *view, t_points *points);
void			draw_line(t_proj p1, t_proj p2, t_fdf *fdf);

// fdf_draw.c
void			draw_map(t_fdf *fdf);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif
