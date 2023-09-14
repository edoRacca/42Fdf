/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:52:48 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:14:20 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_close_window(t_fdf *fdf)
{
	ft_close_all(fdf, 0);
}

void	ft_close_cordinates(t_point **cordinates, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		free(cordinates[i]);
		i++;
	}
	free(cordinates);
}

void	ft_close_all(t_fdf *fdf, int code)
{
	ft_close_cordinates(fdf->map->cordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_image(fdf->mlx, fdf->image->image);
	free(fdf->image);
	free(fdf->cam);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free(fdf);
	error(code);
}

void	ft_close_map(t_fdf *fdf, int code)
{
	ft_close_cordinates(fdf->map->cordinates, fdf->map->max_x);
	free(fdf->map);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf);
	error(code);
}
