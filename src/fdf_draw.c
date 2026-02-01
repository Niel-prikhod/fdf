/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:37:49 by dprikhod          #+#    #+#             */
/*   Updated: 2026/02/01 13:29:11 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
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
			p1 = apply_isometric(fdf->view, &fdf->map->points[y][x]);
			if (x < fdf->map->width - 1)
			{
				p_r = apply_isometric(fdf->view, &fdf->map->points[y][x + 1]);
				draw_line(p1, p_r, fdf);
			}
			if (y < fdf->map->height - 1)
			{
				p_d = apply_isometric(fdf->view, &fdf->map->points[y + 1][x]);
				draw_line(p1, p_d, fdf);
			}
			x++;
		}
		y++;
	}
}
