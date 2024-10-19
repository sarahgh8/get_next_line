#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
#endif

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_variables
{
    int     i;
    int     j;
    ssize_t     bytes;
} t_variables;
size_t  ft_strlen(char *str);
char *get_next_line(int fd);


#endif