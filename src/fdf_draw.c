/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:37:49 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/26 14:50:31 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_proj p1, t_proj p2, t_fdf *fdf)
{
}

void	draw_map(t_fdf *fdf)
{
	t_proj	p1;
	t_proj	p_r;
	t_proj	p_d;
	int		x;
	int		y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			p1 = apply_isometric(fdf->view, &fdf->map->points[x][y]);
			x++;
			if (x < fdf->map->width - 1)
			{
				p_r = apply_isometric(fdf->view, &fdf->map->points[x + 1][y]);
				draw_line(p1, p_r, fdf);
			}
			if (y < fdf->map->height - 1)
			{
				p_d = apply_isometric(fdf->view, &fdf->map->points[x][y + 1]);
				draw_line(p1, p_d, fdf);
			}
		}
		y++;
	}
}
