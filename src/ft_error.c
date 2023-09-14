/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:36:44 by eraccane          #+#    #+#             */
/*   Updated: 2023/09/13 10:16:14 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error(int code)
{
	if (code == 0)
		ft_printf("FdF project closed\n");
	else if (code == 1)
		ft_printf("ERROR: Exptected right map path.\n");
	else if (code == 2)
		ft_printf("ERROR: invalid file (not found / not .fdf file).\n");
	else if (code == 3)
		ft_printf("Cannot initialize fdf.\n");
	else if (code == 4)
		ft_printf("Cannot parse map.\n");
	else if (code == 5)
		ft_printf("Cannot create image.\n");
	else if (code == 6)
		ft_printf("Cannot initialize camera.\n");
	else if (code == 7)
		ft_printf("Unable to render map.\n");
	else if (code == 8)
		ft_printf("Unable to initialize colors.\n");
	exit(code);
}
