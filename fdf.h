/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:50:38 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/16 21:59:31 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		height;
	int		width;
	char	**points;
}			t_map;

#endif
