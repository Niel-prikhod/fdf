/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:36:48 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/22 21:40:14 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_lines(char *filename)
{
	int		fd;
	int		height;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	while ((buf = get_next_line(fd)) != NULL)
	{
		height++;
		free(buf);
	}
	close(fd);
	return (height);
}
