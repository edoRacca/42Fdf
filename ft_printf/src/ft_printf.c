/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:03:05 by eraccane          #+#    #+#             */
/*   Updated: 2023/04/28 11:03:08 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
//#include <stdio.h>

int	ft_format(int fd, const char c, va_list args)
{
	int		len;

	len = 0;
	if (c == 'c')
		len += ft_format_char(fd, va_arg(args, int));
	else if (c == 's')
		len += ft_format_str(fd, va_arg(args, char *));
	else if (c == 'p')
		len += ft_format_ptr(fd, va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_format_int(fd, va_arg(args, int));
	else if (c == 'u')
		len += ft_format_uns(fd, va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_format_hex(fd, c, va_arg(args, unsigned int));
	else if (c == '%')
		len += ft_format_perc(fd);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(1, str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	//int	*p = 0;

	ft_printf("Char: %c\n", 'H');
	ft_printf("String: %s\n", "Hello");
	ft_printf("Void *pointer: %p\n", 0);
	printf("Void *pointer printf: %p\n", 0);
	ft_printf("Decimal (base 10): %d\n", 10);
	ft_printf("Zero Decimal (base 10): %d\n", 0);
	ft_printf("Negative Decimal (base 10): %d\n", -10);
	ft_printf("Integer: %i\n", 22);
	ft_printf("Zero Integer: %i\n", 0);
	ft_printf("Negative Integer: %i\n", -22);
	ft_printf("Unsigned: %u\n", 5);
	ft_printf("Zero Unsigned: %u\n", 0);
	ft_printf("Negative Unsigned: %u\n", -5);
	ft_printf("Hexadecimal (lower): %x\n", 75);
	ft_printf("Hexadecimal (upper): %X\n", 75);
}*/
