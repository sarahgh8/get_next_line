#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;

    fd = open("test.txt", O_RDWR);
    write(fd, argv[1], ft_strlen(argv[1]));
    close(fd);

    fd = open("test.txt", O_RDWR);
    printf("%s\n", get_next_line(fd));
    close(fd);

    return (0);
}