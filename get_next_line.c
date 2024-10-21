/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sghunmin <sghunmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:02:08 by sghunmin          #+#    #+#             */
/*   Updated: 2024/10/21 09:06:43 by sghunmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*until_newline(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i])
	{
		i++;
	}
	if (str[i] == '\n')
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j < i)
	{
		res[j] = str[j];
		j++;
	}
	free(str);
	res[j] = '\0';
	return (res);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	if (dest == NULL && src == NULL)
		return (NULL);
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		p2[i] = p1[i];
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static ssize_t	bytes;
	char			*line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0] != '\0')
	{
		if (bytes < BUFFER_SIZE)
			return (NULL);
		temp = ft_strchr(buffer, '\n') + 1;
		ft_memcpy(buffer, temp, ft_strlen(temp));
		buffer[ft_strlen(temp)] = '\0';
	}
	else
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (NULL);
	}
	line = ft_strdup("");
	if (!line)
		return (NULL);
	while (bytes > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			free(line);
			return (NULL);
		}
		if (ft_strchr(line, '\n'))
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		if (bytes < BUFFER_SIZE)
		{
			buffer[bytes] = '\0';
			line = ft_strjoin(line, buffer);
			if (!line)
			{
				free(line);
				return (NULL);
			}
			break ;
		}
	}
	return (until_newline(line));
}
