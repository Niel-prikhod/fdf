/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:29:04 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/26 13:56:57 by dprikhod         ###   ########.fr       */
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
