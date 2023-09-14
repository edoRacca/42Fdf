/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:51:53 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:19:09 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_image	*ft_init_image(void *mlx)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	image->addr = mlx_get_data_addr(image->image, &image->bits_per_pixel, 
			&image->line_length, &image->endian);
	image->line = NULL;
	return (image);
}

t_cam	*ft_init_cam(t_map *map)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->projection = ISOMETRIC;
	cam->color_pallet = FALSE;
	cam->scale_factor = scale_to_fit(map);
	cam->scale_z = 1;
	cam->move_x = WIN_WIDTH / 2;
	cam->move_y = WIN_HEIGHT / 2;
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	return (cam);
}

t_fdf	*ft_init_fdf(char *filename)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error(3);
	fdf->map = ft_read_map(filename, fdf);
	if (!fdf->map)
	{
		free(fdf);
		error(4);
	}
	fdf->mlx = mlx_init();
	fdf->win_x = WIN_WIDTH;
	fdf->win_y = WIN_HEIGHT;
	fdf->win = mlx_new_window(fdf->mlx, fdf->win_x, fdf->win_y, WIN_NAME);
	fdf->image = ft_init_image(fdf->mlx);
	if (!fdf->image)
		ft_close_map(fdf, 5);
	fdf->cam = ft_init_cam(fdf->map);
	if (!fdf->cam)
		ft_close_all(fdf, 6);
	return (fdf);
}

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->cordinates = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->max_z = 0;
	map->min_z = 0;
	return (map);
}

t_line	*ft_init_line(t_fdf *fdf, t_point start, t_point end)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.z = end.z;
	line->end.color = end.color;
	line->transform_z = fmax((fdf->map->max_z - fdf->map->min_z), 
			fmax(fdf->map->max_x, fdf->map->max_y));
	return (line);
}
