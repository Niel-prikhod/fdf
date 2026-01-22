/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:50:38 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/22 21:50:33 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

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

typedef struct s_fdf
{
	void		*mlx;
	void		*window;
	t_map		*map;
}				t_fdf;

// fdf_utils.c
void			fdf_clean_all(t_fdf *fdf);
t_fdf			*fdf_init(void);

// fdf_parser.c
t_map			*parse_dot_fdf(int fd);

// fdf_file_handle.c
int				count_lines(char *filename);

#endif
