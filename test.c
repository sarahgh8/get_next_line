#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;

    fd = open("test.txt", O_RDONLY);

    char *str =  get_next_line(fd);
    printf("%s", str);
    free(str);
    
    // str =  get_next_line(fd);
    // printf("%s", str);
    // free(str);

    // str =  get_next_line(fd);
    // printf("%s", str);
    // free(str);

    // str =  get_next_line(fd);
    // printf("%s", str);
    // free(str);

    return (0);
}