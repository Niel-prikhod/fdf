/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:01:17 by dprikhod          #+#    #+#             */
/*   Updated: 2026/02/01 11:46:30 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *fdf)
{
	fdf_clean_all(fdf);
	exit(0);
	return (0);
}

int	if_esc_pressed(int key_code, t_fdf *fdf)
{
	if (key_code == ESC_CODE)
		close_window(fdf);
	return (0);
}

void	fdf_hook(t_fdf *fdf)
{
	mlx_hook(fdf->window, 2, 1L << 0, (int (*)())(void *)if_esc_pressed, fdf);
	mlx_hook(fdf->window, 17, 0, (int (*)())(void *)close_window, fdf);
}
