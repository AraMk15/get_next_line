/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armkrtch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:25:16 by armkrtch          #+#    #+#             */
/*   Updated: 2025/04/27 19:17:32 by armkrtch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_free(char *res, char *buff)
{
	char	*temp;

	temp = ft_strjoin(res, buff);
	free(res);
	return (temp);
}

static char	*ft_trim_buffer(char *buffer)
{
	char	*newline;
	char	*rest;

	newline = ft_strchr(buffer, '\n');
	if (!newline)
	{
		free(buffer);
		return (NULL);
	}
	rest = ft_strndup(newline + 1, ft_strlen(newline + 1));
	free(buffer);
	return (rest);
}

static char	*ft_set_line(char *buffer)
{
	int	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (ft_strndup(buffer, i));
}

static char	*ft_fill_line_buffer(int fd, char *str)
{
	t_buff	buff_data;

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	buff_data.buff = malloc(BUFFER_SIZE + 1);
	if (!buff_data.buff)
		return (NULL);
	buff_data.read_size = 1;
	while (!ft_strchr(str, '\n') && buff_data.read_size > 0)
	{
		buff_data.read_size = read(fd, buff_data.buff, BUFFER_SIZE);
		if (buff_data.read_size < 0)
		{
			free(buff_data.buff);
			return (NULL);
		}
		buff_data.buff[buff_data.read_size] = '\0';
		str = ft_join_free(str, buff_data.buff);
	}
	return (free(buff_data.buff), str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	*buffer = ft_fill_line_buffer(fd, buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_set_line(buffer[fd]);
	buffer[fd] = ft_trim_buffer(buffer[fd]);
	return (line);
}
