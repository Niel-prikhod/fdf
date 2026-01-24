/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:55:42 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/24 17:57:07 by dprikhod         ###   ########.fr       */
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
	if (!fdf_parser(argv[1], fdf->map))
		return (fdf_clean_all(fdf), 1);
	mlx_loop(fdf->mlx);
	fdf_clean_all(fdf);
	return (0);
}
