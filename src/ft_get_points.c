/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:53:00 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:16:50 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_fill_points(char *point, t_map *map, int coord_x, int coord_y)
{
	char	**info;
	int		i;

	map->cordinates[coord_x][coord_y].x = (float)coord_x;
	map->cordinates[coord_x][coord_y].y = (float)coord_y;
	if (ft_strchr(point, ','))
	{
		info = ft_split(point, ',');
		map->cordinates[coord_x][coord_y].z = (float)ft_atoi(info[0]);
		map->cordinates[coord_x][coord_y].color = ft_atoi_base(info[1], 
				HEXADECIMAL_L_BASE);
		i = 0;
		while (info[i])
			free(info[i++]);
		free(info);
	}
	else
	{
		map->cordinates[coord_x][coord_y].z = (float)ft_atoi(point);
		map->cordinates[coord_x][coord_y].color = -1;
	}
	if (map->cordinates[coord_x][coord_y].z > map->max_z)
		map->max_z = map->cordinates[coord_x][coord_y].z;
	if (map->cordinates[coord_x][coord_y].z < map->min_z)
		map->min_z = map->cordinates[coord_x][coord_y].z;
}

void	ft_get_points(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**split;
	int		coord[2];

	fd = open(filename, O_RDONLY);
	coord[1] = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		split = ft_split(line, ' ');
		coord[0] = 0;
		while (coord[0] < map->max_x)
		{
			ft_fill_points(split[coord[0]], map, coord[0], coord[1]);
			free(split[coord[0]]);
			coord[0]++;
		}
		free(split);
		free(line);
		coord[1]++;
	}
	close(fd);
}
