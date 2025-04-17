#include "get_next_line.h"

char *ft_read_file(int fd, char *buffer)
{
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    buffer = ft_read_file(fd, buffer);
    if(!buffer)
        return (NULL);
}