#include "get_next_line.h"

int main (int argc, char **argv)
{
    int fd;

    fd = open("nl", O_RDONLY);

    char *str =  get_next_line(fd);
    printf("%s%%\n", str);
    free(str);

    char *str1 =  get_next_line(fd);
    printf("%s%%\n", str1);
    free(str1);

    // char *str2 =  get_next_line(fd);
    // printf("%s%%", str2);
    // free(str2);

    // char *str3 =  get_next_line(fd);
    // printf("%s", str3);
    // free(str3);

    // char *str4 =  get_next_line(fd);
    // printf("%s", str4);
    // free(str4);

    // char *str5 =  get_next_line(fd);
    // printf("%s", str5);
    // free(str5);

    return (0);
}
