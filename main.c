#include "get_next_line.h"

int main()
{
    int   fd = open("test", O_RDONLY);
    char *new_line;
    while ((new_line = get_next_line(fd)))
        printf("%s", new_line);
}