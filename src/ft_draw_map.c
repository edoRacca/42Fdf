/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:52:03 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:15:56 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->line_length) + ((int)x * 4);
	if (image->endian == 1)
	{
		image->addr[pixel + 0] = (color >> 24);
		image->addr[pixel + 1] = (color >> 16) & 0xff;
		image->addr[pixel + 2] = (color >> 8) & 0xff;
		image->addr[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->addr[pixel + 0] = (color) & 0xff;
		image->addr[pixel + 1] = (color >> 8) & 0xff;
		image->addr[pixel + 2] = (color >> 16) & 0xff;
		image->addr[pixel + 3] = (color >> 24);
	}
}

void	ft_bresenham(t_fdf *fdf, t_point start, t_point end)
{
	float	x_step;
	float	y_step;
	int		max_steps;
	int		i_line;
	t_color	*color;

	x_step = end.x - start.x;
	y_step = end.y - start.y;
	max_steps = (int)max(absolute(x_step), absolute(y_step));
	x_step /= max_steps;
	y_step /= max_steps;
	color = ft_color_init(start, end);
	if (!color)
		ft_close_all(fdf, 8);
	i_line = 0;
	while (i_line < max_steps)
	{
		start.color = ft_get_color(color, i_line++, max_steps);
		if (start.x > 0 && start.y > 0 && start.x < WIN_WIDTH && 
			start.y < WIN_HEIGHT)
			ft_pixel_to_image(fdf->image, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
	free(color);
}

void	ft_clear_image(t_image *image, int image_size)
{
	int	x;
	int	y;

	ft_bzero(image->addr, image_size);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ft_pixel_to_image(image, x, y, BACKGROUND_DEFAULT);
			x++;
		}
		y++;
	}
}
