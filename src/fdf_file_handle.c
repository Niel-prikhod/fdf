/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:36:48 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/24 17:16:24 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_values_in_line(const char *line)
{
	int	count;
	int	in_value;

	count = 0;
	in_value = 0;
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
		{
			if (!in_value)
			{
				count++;
				in_value = 1;
			}
		}
		else
			in_value = 0;
		line++;
	}
	return (count);
}

int	get_map_dimensions(const char *filename, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	map->width = count_values_in_line(line);
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		map->height++;
		free(line);
	}
	map->height++;
	close(fd);
	return (0);
}

bool	check_args(int ac, char **av)
{
	size_t	len;

	if (ac != 2)
		return (false);
	len = ft_strlen(av[1]);
	if (len < 5)
		return (false);
	if (ft_strncmp(av[1] + len - 4, ".fdf", 4) != 0)
		return (false);
	return (true);
}
