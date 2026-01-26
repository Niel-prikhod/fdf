/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:50:38 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/26 11:15:40 by dprikhod         ###   ########.fr       */
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

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 1920

typedef struct s_points
{
	int			x;
	int			y;
	int			z;
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
	float		z_scale;
}				t_view;

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

// fdf_parser.c
bool			fdf_parser(const char *filename, t_map *map);

// fdf_file_handle.c
int				get_map_dimensions(const char *filename, t_map *map);
bool			check_args(int ac, char **av);

#endif
