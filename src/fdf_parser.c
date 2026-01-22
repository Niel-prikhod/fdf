/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 21:05:10 by dprikhod          #+#    #+#             */
/*   Updated: 2026/01/22 20:32:11 by dprikhod         ###   ########.fr       */
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
 * fill t_points with data about one given point
 * if color not given by file, it is set to white (0xFFFFFF)
 */
{
	t_points point;
	char **z;

	z = ft_split(value, ',');
	point.x = x;
	point.y = y;
	point.z = ft_atoi(z[0]);
	if (z[1])
		point.color = parse_hex(z[02]);
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

t_map	*parse_dot_fdf(int fd)
{
	t_map	*map;
	char	*buf;
	int		y;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	buf = get_next_line(fd);
	map->width = ft_strlen(buf);
	y = 0;
	while (buf)
	{
		map->points[y] = malloc(sizeof(t_points) * map->width);
		parse_line(buf, map, y);
		y++;
		free(buf);
		buf = get_next_line(fd);
	}
	map->height = y;
	return (map);
}
