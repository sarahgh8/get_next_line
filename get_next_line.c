#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *ptr;
    ssize_t size;

    ptr = (char *)malloc(100);
    size = read(fd, ptr, 12);

    ptr[size] = '\0';
    return(ptr);
}