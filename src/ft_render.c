/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:51:28 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:30:31 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_render_line(t_fdf *fdf, t_point start, t_point end)
{
	start.z *= fdf->cam->scale_z;
	end.z *= fdf->cam->scale_z;
	ft_put_color(fdf, &start);
	ft_put_color(fdf, &end);
	fdf->image->line = ft_init_line(fdf, start, end);
	if (!fdf->image->line)
		ft_close_all(fdf, 7);
	ft_rotate(fdf->cam, fdf->image->line);
	ft_projection(fdf->cam, fdf->image->line);
	ft_transform(fdf->cam, fdf->image->line);
	ft_bresenham(fdf, fdf->image->line->start, fdf->image->line->end);
	free(fdf->image->line);
}

void	ft_render(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_clear_image(fdf->image, MAX_PIXEL * 4);
	y = 0;
	while (y < fdf->map->max_y)
	{
		x = 0;
		while (x < fdf->map->max_x)
		{
			if (x < fdf->map->max_x - 1)
				ft_render_line(fdf, fdf->map->cordinates[x][y],
					fdf->map->cordinates[x + 1][y]);
			if (y < fdf->map->max_y - 1)
				ft_render_line(fdf, fdf->map->cordinates[x][y],
					fdf->map->cordinates[x][y + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image->image, 0, 0);
	ft_print_menu(fdf);
}
