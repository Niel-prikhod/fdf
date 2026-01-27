/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:29:04 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/27 16:10:39 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_def_view(t_fdf *fdf)
{
	fdf->view->zoom = ft_min_int((WINDOW_HEIGHT / fdf->map->height),
			WINDOW_WIDTH / fdf->map->width) / 2;
	fdf->view->offset_x = WINDOW_WIDTH / 2;
	fdf->view->offset_y = WINDOW_HEIGHT / 2;
	fdf->view->z_scale = 0.1;
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
	x *= view->zoom;
	y *= view->zoom;
	proj.x_proj = (int)x + view->offset_x;
	proj.y_proj = (int)y + view->offset_y;
	proj.color = points->color;
	return (proj);
}

static void	init_algo(t_algo *a, t_proj p1, t_proj p2)
{
	a->dx = abs(p2.x_proj - p1.x_proj);
	a->dy = -abs(p2.y_proj - p1.y_proj);
	a->sx = -1;
	if (p1.x_proj < p2.x_proj)
		a->sx = 1;
	a->sy = -1;
	if (p1.y_proj < p2.y_proj)
		a->sy = 1;
	a->err = a->dx + a->dy;
}

void	draw_line(t_proj p1, t_proj p2, t_fdf *fdf)
{
	t_algo	a;

	init_algo(&a, p1, p2);
	while (1)
	{
		my_mlx_pixel_put(fdf->img, p1.x_proj, p1.y_proj, p1.color);
		if (p1.x_proj == p2.x_proj && p1.y_proj == p2.y_proj)
			break ;
		a.e2 = a.err * 2;
		if (a.e2 >= a.dy)
		{
			a.err += a.dy;
			p1.x_proj += a.sx;
		}
		if (a.e2 <= a.dx)
		{
			a.err += a.dx;
			p1.y_proj += a.sy;
		}
	}
}
