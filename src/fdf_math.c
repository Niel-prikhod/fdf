/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:29:04 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/27 11:46:44 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_def_view(t_fdf *fdf)
{
	fdf->view->zoom = ft_min_int((WINDOW_HEIGHT / fdf->map->height),
			WINDOW_WIDTH / fdf->map->width) / 2;
	fdf->view->offset_x = WINDOW_WIDTH / 2;
	fdf->view->offset_y = WINDOW_HEIGHT / 2;
	fdf->view->z_scale = 1;
	fdf->view->map_center_x = (float)(fdf->map->width - 1) / 2;
	fdf->view->map_center_y = (float)(fdf->map->height - 1) / 2;
}

t_proj	apply_isometric(t_view *view, t_points *points)
{
	t_proj	proj;
	float	x;
	float	y;
	float	z;

	z = (float)points->z_raw * view->z_scale;
	x = (float)points->x_raw - view->map_center_x;
	y = (float)points->y_raw - view->map_center_y;
	x = (x + y) * sin(ANGLE);
	y = (x - y) * cos(ANGLE) - z;
	proj.x_proj = (int)x + view->offset_x;
	proj.y_proj = (int)y + view->offset_y;
	proj.color = points->color;
	return (proj);
}

void	draw_line(t_proj p1, t_proj p2, t_fdf *fdf)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	dx = abs(p2.x_proj - p1.x_proj);
	dy = -abs(p2.y_proj - p1.y_proj);
	if (p1.x_proj < p2.x_proj)
		sx = 1;
	else
		sx = -1;
	if (p1.y_proj < p2.y_proj)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	while (1)
	{
		my_mlx_pixel_put(fdf->img, p1.x_proj, p1.y_proj, p1.color);
		if (p1.x_proj == p2.x_proj && p1.y_proj == p2.y_proj)
			break ;
		if (err * 2 >= dy)
		{
			err += dy;
			p1.x_proj += sx;
		}
		if (err * 2 <= dx)
		{
			err += dx;
			p1.y_proj += sy;
		}
	}
}
