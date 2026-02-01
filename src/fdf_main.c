/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:55:42 by dprikhod          #+#    #+#             */
/*   Updated: 2026/02/01 14:11:45 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (!check_args(argc, argv))
	{
		ft_putstr_fd("Usage: ./fdf <map_file.fdf>\n", STDERR_FILENO);
		return (1);
	}
	fdf = fdf_init();
	if (!fdf)
		return (1);
	ft_printf("Parsing...\n");
	if (!fdf_parser(argv[1], fdf->map))
		return (fdf_clean_all(fdf), 1);
	set_def_view(fdf);
	fdf->img = init_img(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fdf->img)
		return (fdf_clean_all(fdf), 1);
	ft_printf("Rendering...\n");
	draw_map(fdf);
	ft_printf("Done!\n");
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img->img_ptr, 0, 0);
	fdf_hook(fdf);
	mlx_loop(fdf->mlx);
	fdf_clean_all(fdf);
	return (0);
}
