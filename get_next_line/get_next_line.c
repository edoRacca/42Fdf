/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraccane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:48:07 by eraccane          #+#    #+#             */
/*   Updated: 2023/04/03 16:03:27 by eraccane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nextline(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = ft_gnl_calloc(((ft_strlen(str)) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (str[i])
	{
		line[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (line);
}

char	*ft_jfree(char *freed, char *s)
{
	char	*buf;

	buf = ft_strjoin(freed, s);
	free(freed);
	return (buf);
}

char	*ft_read(int fd, char *buf)
{
	char	*str;
	int		bread;

	if (!buf)
		buf = ft_gnl_calloc(1, 1);
	str = ft_gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	bread = 1;
	while (bread > 0)
	{
		bread = read(fd, str, BUFFER_SIZE);
		if (bread == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		str[bread] = 0;
		buf = ft_jfree(buf, str);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(str);
	return (buf);
}

char	*ft_newline(char *buffer)
{
	char	*linea;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	linea = ft_gnl_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		linea[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		linea[i++] = '\n';
	return (linea);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	linea = ft_newline(buffer);
	buffer = ft_nextline(buffer);
	return (linea);
}
