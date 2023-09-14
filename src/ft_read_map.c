/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:53:13 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:28:53 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_get_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_isprint(*line))
			height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	ft_get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;
	int		new_width;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (0);
	width = (int)ft_split_count(line, ' ');
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new_width = (int)ft_split_count(line, ' ');
		if (width != new_width)
			return (0);
		free(line);
	}
	close(fd);
	return (width);
}

void	ft_center_origin(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		while (x < map->max_x)
		{
			map->cordinates[x][y].x -= map->max_x / 2;
			map->cordinates[x][y].y -= map->max_y / 2;
			x++;
		}
		y++;
	}
}

int	ft_check_fdf_file(char *av)
{
	int		i;

	i = ft_strlen(av);
	if (ft_strncmp(&av[i - 4], ".fdf", 5) != 0)
		return (1);
	return (0);
}

t_map	*ft_read_map(char *filename, t_fdf *fdf)
{
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0 || ft_check_fdf_file(filename) == 1)
	{
		free(fdf);
		error(2);
	}
	close(fd);
	map = ft_init_map();
	if (!map)
		return (NULL);
	map->max_x = ft_get_width(filename);
	map->max_y = ft_get_height(filename);
	map->cordinates = ft_init_cordinates(map->max_x, map->max_y);
	if (!map->cordinates)
	{
		free(map);
		return (NULL);
	}
	ft_get_points(filename, map);
	ft_center_origin(map);
	return (map);
}
