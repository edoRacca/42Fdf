/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:04:13 by eraccane          #+#    #+#             */
/*   Updated: 2023/04/28 11:04:15 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_format(int fd, const char c, va_list args);
int		ft_format_char(int fd, int c);
int		ft_format_perc(int fd);
int		ft_format_str(int fd, char *s);
int		ft_format_int(int fd, int n);
int		ft_format_uns(int fd, unsigned int n);
int		ft_format_hex(int fd, char c, unsigned int n);
void	ft_print_hex(int fd, char c, unsigned int n);
int		ft_format_ptr(int fd, unsigned long long p);
void	ft_print_ptr(int fd, unsigned long long p);
int		ft_ptrlen(unsigned long long p);
char	*ft_uinttoa(unsigned int n);
int		ft_numlen(int n);

#endif
