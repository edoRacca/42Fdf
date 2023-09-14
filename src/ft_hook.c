/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:46:13 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:17:08 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_project(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_P)
		fdf->cam->projection = PERSPECTIVE;
	else if (keycode == KEY_I)
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_O)
		fdf->cam->projection = TOP;
}

void	ft_key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->cam->alpha -= (5 * ANG_1);
	else if (keycode == KEY_W)
		fdf->cam->alpha += (5 * ANG_1);
	else if (keycode == KEY_A)
		fdf->cam->gamma -= (5 * ANG_1);
	else if (keycode == KEY_D)
		fdf->cam->gamma += (5 * ANG_1);
	else if (keycode == KEY_Q)
		fdf->cam->beta -= (5 * ANG_1);
	else if (keycode == KEY_E)
		fdf->cam->beta += (5 * ANG_1);
}

void	ft_key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->cam->scale_factor += 1;
	else if (keycode == KEY_MINUS)
		fdf->cam->scale_factor -= 1;
	else if (keycode == KEY_Z && fdf->cam->scale_z > -1)
		fdf->cam->scale_z -= 0.1;
	else if (keycode == KEY_X && fdf->cam->scale_z < 1)
		fdf->cam->scale_z += 0.1;
}

void	ft_key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->cam->move_x += 10;
	else if (keycode == KEY_LEFT)
		fdf->cam->move_x -= 10;
	else if (keycode == KEY_DOWN)
		fdf->cam->move_y += 10;
	else if (keycode == KEY_UP)
		fdf->cam->move_y -= 10;
}

int	ft_press_button(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		ft_close_all(fdf, 0);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT || keycode == KEY_UP
		|| keycode == KEY_DOWN)
		ft_key_translate(keycode, fdf);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS || keycode == KEY_Z
		|| keycode == KEY_X)
		ft_key_scale(keycode, fdf);
	else if (keycode == KEY_A || keycode == KEY_S || keycode == KEY_D
		|| keycode == KEY_Q || keycode == KEY_W || keycode == KEY_E)
		ft_key_rotate(keycode, fdf);
	else if (keycode == KEY_P || keycode == KEY_I || keycode == KEY_O)
		ft_key_project(keycode, fdf);
	else if (keycode == KEY_SPACE)
	{
		if (fdf->cam->color_pallet == FALSE)
			fdf->cam->color_pallet = TRUE;
		else
			fdf->cam->color_pallet = FALSE;
	}
	else if (keycode == KEY_R)
		ft_reset(fdf);
	ft_render(fdf);
	return (0);
}
