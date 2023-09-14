/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cordinates.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:55:53 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:17:41 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	**ft_init_cordinates(int width, int height)
{
	t_point	**cordinates;
	int		i;
	int		j;

	cordinates = malloc(width * sizeof(t_point *));
	if (!cordinates)
		return (NULL);
	i = 0;
	while (i < width)
	{
		cordinates[i] = malloc(height * sizeof(t_point));
		if (!cordinates[i])
			return (NULL);
		j = 0;
		while (j < height)
		{
			cordinates[i][j].x = 0;
			cordinates[i][j].y = 0;
			cordinates[i][j].z = 0;
			cordinates[i][j].color = 0;
			j++;
		}
		i++;
	}
	return (cordinates);
}

float	scale_to_fit(t_map *map)
{
	float	scale_x;
	float	scale_y;
	float	scale_factor;

	scale_x = WIN_WIDTH / map->max_x;
	scale_y = WIN_HEIGHT / map->max_y;
	scale_factor = min(scale_x, scale_y);
	if (scale_factor < 4)
		return (2);
	return (scale_factor / 2);
}

void	ft_reset(t_fdf *fdf)
{
	fdf->cam->scale_factor = scale_to_fit(fdf->map);
	fdf->cam->scale_z = 1;
	fdf->cam->move_x = WIN_WIDTH / 2;
	fdf->cam->move_y = WIN_HEIGHT / 2;
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}
