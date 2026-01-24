/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:16:28 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/24 18:59:53 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clean_all(t_fdf *fdf)
{
	if (!fdf)
		return ;
	if (fdf->map)
	{
		if (fdf->map->points[0])
			free(fdf->map->points[0]);
		free(fdf->map->points);
		free(fdf->map);
	}
	if (fdf->window)
		mlx_destroy_window(fdf->mlx, fdf->window);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free(fdf);
	fdf = NULL;
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
	fdf->window = mlx_new_window(fdf->mlx, 1280, 720, "FDF");
	if (!fdf->window)
		return (mlx_destroy_display(fdf->mlx), free(fdf), NULL);
	fdf->map = malloc(sizeof(t_map));
	if (!fdf->map)
		return (fdf_clean_all(fdf), NULL);
	return (fdf);
}
