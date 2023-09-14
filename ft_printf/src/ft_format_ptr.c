/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:03:03 by eraccane          #+#    #+#             */
/*   Updated: 2023/04/29 17:03:04 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_ptrlen(unsigned long long p)
{
	int	len;

	len = 0;
	while (p != 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

void	ft_print_ptr(int fd, unsigned long long p)
{
	if (p >= 16)
	{
		ft_print_ptr(1, p / 16);
		ft_print_ptr(1, p % 16);
	}
	else
	{
		if (p <= 9)
			ft_putchar_fd((p + '0'), fd);
		else
			ft_putchar_fd((p - 10 + 'a'), fd);
	}
}

int	ft_format_ptr(int fd, unsigned long long p)
{
	int	len;

	len = 0;
	if (!p)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		if (p == 0)
			len += write(1, "0", 1);
		else
		{
			ft_print_ptr(fd, p);
			len += ft_ptrlen(p);
		}
	}
	return (len);
}
