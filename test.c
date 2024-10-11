#include "get_next_line.h"

int main()
{
    int fd, size;
    char *str;

    fd = open("test.txt", O_RDONLY);

    str = get_next_line(fd);
    printf("%s\n", str);

    //size = read(fd, str, 10);

    return 0;
}