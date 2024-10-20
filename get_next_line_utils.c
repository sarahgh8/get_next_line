#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*join;
	size_t	i;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join == NULL)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	join[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (join);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((char)s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
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

char *until_newline(char *str)
{
    int i = 0, j = 0;
    char *res;
    while(str[i - 1] != '\n' && str[i])
        i++;
    res = malloc(i + 1);
    if (!res)
	{
		// free(res);
        return NULL;

	}


    while (j < i)
    {
        res[j] = str[j];
        j++;
    }

    free(str);
    res[j] = '\0';
    return res;
}