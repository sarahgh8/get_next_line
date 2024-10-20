#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	static ssize_t bytes;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;

	if (buffer[0] != '\0')
	{
		if (bytes < BUFFER_SIZE)
			return NULL;
		char *temp = ft_strchr(buffer, '\n') + 1;
		ft_memcpy(buffer, temp, ft_strlen(temp));
		buffer[ft_strlen(temp)] = '\0';
	}
	else
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return NULL;
	}

	// printf("bytes: %ld ==> %s%%", bytes, buffer);
	// if (buffer[0] == '\0')
	// {
	// 	buffer[0] = '';
	// 	// printf("buffer is null");
	// }



	line = ft_strdup("");
	if (!line)
		return NULL;
	while(bytes > 0)
	{
		line = ft_strjoin(line, buffer);
		if (!line)
		{
			free(line);
			return NULL;
		}
		if(ft_strchr(line, '\n'))
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return NULL;
		if (bytes < BUFFER_SIZE)
		{
			buffer[bytes] = '\0';
			line = ft_strjoin(line, buffer);
			if (!line)
			{
				free(line);
				return NULL;
			}
			break;
		}
	}
	return until_newline(line);
}
