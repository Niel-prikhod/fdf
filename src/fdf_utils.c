/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 23:16:28 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/17 07:44:38 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_clean_all(t_fdf *fdf)
{
	int	y;

	y = -1;
	if (!fdf)
		return ;
	if (fdf->map)
	{
		if (fdf->map->points)
		{
			while (y++ < fdf->map->height)
				free(fdf->map->points[y]);
			free(fdf->map->points);
		}
		free(fdf->map);
	}
	if (fdf->window)
		mlx_destroy_window(fdf->mlx, fdf->window);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free(fdf);
	fdf = NULL;
}
