/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:03:43 by eraccane          #+#    #+#             */
/*   Updated: 2023/04/29 17:03:46 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_print_hex(int fd, char c, unsigned int n)
{
	if (n >= 16)
	{
		ft_print_hex(1, c, n / 16);
		ft_print_hex(1, c, n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), fd);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), fd);
			if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), fd);
		}
	}
}

int	ft_format_hex(int fd, char c, unsigned int n)
{
	int				len;

	if (n == 0)
	{
		ft_putnbr_fd(0, fd);
		len = 1;
	}
	else
	{
		ft_print_hex(fd, c, n);
		len = ft_hexlen(n);
	}
	return (len);
}
