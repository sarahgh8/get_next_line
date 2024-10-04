#include "get_next_line.h"

int main()
{
    int fd = open("test.txt", O_RDONLY);
    printf("fd: %d\n", fd);

}