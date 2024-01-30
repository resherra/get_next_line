#include "get_next_line.h"

int main()
{
    int   fd = open("test", O_RDONLY);
    printf("%s\n", get_next_line(fd));
}