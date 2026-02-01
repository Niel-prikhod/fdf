/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:16:28 by dprikhod          #+#    #+#             */
/*   Updated: 2026/02/01 13:19:44 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clean_all(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->map)
	{
		if (fdf->map->points)
		{
			if (fdf->map->points[0])
				free(fdf->map->points[0]);
			free(fdf->map->points);
		}
		free(fdf->map);
	}
	if (fdf->view)
		free(fdf->view);
	if (fdf->window)
		mlx_destroy_window(fdf->mlx, fdf->window);
	if (fdf->img)
	{
		mlx_destroy_image(fdf->mlx, fdf->img->img_ptr);
		free(fdf->img);
	}
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free(fdf);
}

t_fdf	*fdf_init(void)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (free(fdf), NULL);
	fdf->window = mlx_new_window(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!fdf->window)
		return (mlx_destroy_display(fdf->mlx), free(fdf), NULL);
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map)
		return (fdf->view = NULL, fdf_clean_all(fdf), NULL);
	fdf->view = malloc(sizeof(t_view));
	if (!fdf->view)
		return (fdf_clean_all(fdf), NULL);
	fdf->img = NULL;
	return (fdf);
}

t_img	*init_img(void *mlx, int width, int height)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img_ptr = mlx_new_image(mlx, width, height);
	if (!img->img_ptr)
		return (free(img), NULL);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
	if (!img->addr)
		return (mlx_destroy_image(mlx, img->img_ptr), free(img), NULL);
	return (img);
}
