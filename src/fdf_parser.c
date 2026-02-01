/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:05:10 by dprikhod          #+#    #+#             */
/*   Updated: 2026/02/01 14:04:26 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_hex(char *str)
{
	int	color;

	if (ft_strncmp(str, "0x", 2) == 0)
		color = ft_atoi_base(str + 2, 16);
	else
		color = ft_atoi_base(str, 16);
	return (color);
}

t_points	parse_single_point(char *value, int x, int y)
/*
 fill t_points with data about one given point if color not given by file,
	it is set to white (0xFFFFFF)
 */
{
	char **z;
	t_points point;

	z = ft_split(value, ',');
	point.x_raw = x;
	point.y_raw = y;
	point.z_raw = ft_atoi(z[0]);
	if (z[1])
		point.color = parse_hex(z[1]);
	else
		point.color = 0xFFFFFF;
	ft_clr_split(z);
	return (point);
}

void	parse_line(char *line, t_map *map, int y)
{
	int		x;
	char	**z;

	z = ft_split(line, ' ');
	x = 0;
	while (x < map->width)
	{
		map->points[y][x] = parse_single_point(z[x], x, y);
		x++;
	}
	ft_clr_split(z);
}

bool	extract_data(int fd, t_map *map)
{
	t_points	*all_points;
	int			y;
	char		*buf;

	buf = get_next_line(fd);
	all_points = malloc(sizeof(t_points) * map->height * map->width);
	if (!all_points)
		return (false);
	map->points = malloc(sizeof(t_points *) * map->height);
	if (!map->points)
		return (free(all_points), false);
	y = 0;
	while (buf)
	{
		map->points[y] = &all_points[y * map->width];
		parse_line(buf, map, y);
		y++;
		free(buf);
		buf = get_next_line(fd);
	}
	return (true);
}

bool	fdf_parser(const char *filename, t_map *map)
{
	int		fd;
	bool	result;

	if (get_map_dimensions(filename, map) < 0)
		return (ft_putstr_fd("WRONG DIMENSIONS\n", 2), false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	result = extract_data(fd, map);
	close(fd);
	return (result);
}
