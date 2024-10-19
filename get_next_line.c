#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *res;
    char    *buff;
    t_variables     var;

    var.i = 0;
    var.j = 0;
    var.bytes = 1;
    res = malloc(sizeof(char) * BUFFER_SIZE);
    if(res == NULL)
    {
        free(res);
        return (NULL);
    }
    buff = malloc(sizeof(char) * BUFFER_SIZE);
    if(buff == NULL)
    {
        free(res);
        free(buff);
        return (NULL);
    }
    while (var.bytes > 0)
    {
        var.bytes = read(fd, buff, BUFFER_SIZE);
        while (ft_strchr(buff, '\n'))
        {
            res[var.j] = buff[var.i];
            var.i++;
            var.j++;
        }
        res[var.j] = '\0';
        free(buff);
        return (res);
    }
    return (NULL);
}
