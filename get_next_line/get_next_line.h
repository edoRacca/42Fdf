/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:18 by eraccane          #+#    #+#             */
/*   Updated: 2023/04/03 16:02:49 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <sys/types.h> 
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h> 
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *pointer, size_t size);
char	*ft_gnl_calloc(size_t numElem, size_t dimElem);
char	*ft_linea(char *buffer);
char	*read_fd(int fd, char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_jfree(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);
char	*ft_nextLine(char *str);

#endif
