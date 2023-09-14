/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:03:35 by eraccane          #+#    #+#             */
/*   Updated: 2023/04/29 17:03:35 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_uns_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uinttoa(unsigned int n)
{
	int		len;
	char	*s;

	len = ft_uns_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (n != 0)
	{
		s[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (s);
}

int	ft_format_uns(int fd, unsigned int n)
{
	int		len;
	char	*s;

	if (n == 0)
	{
		ft_putnbr_fd(0, fd);
		len = 1;
	}
	else
	{
		s = ft_uinttoa(n);
		ft_putstr_fd(s, fd);
		len = ft_strlen(s);
		free(s);
	}
	return (len);
}
