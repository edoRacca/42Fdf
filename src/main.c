/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:53:28 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:31:32 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	expose_handle(t_fdf *fdf)
{
	ft_render(fdf);
	return (0);
}

int	main(int ac, char *av[])
{
	char	*file_name;
	t_fdf	*fdf;

	if (ac != 2)
		error(1);
	file_name = av[1];
	fdf = ft_init_fdf(file_name);
	ft_render(fdf);
	mlx_hook(fdf->win, 17, 0L, (void *)ft_close_window, (void *)fdf);
	mlx_key_hook(fdf->win, &ft_press_button, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_loop(fdf->mlx);
}
