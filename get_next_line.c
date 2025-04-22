#include "get_next_line.h"

char *ft_set_line(char *buffer)
{
    char *new;
    int i;

    i = 0;
    if (buffer == 0)
        return (NULL);
    while (buffer && buffer[i] != '\n')
        i++;
    new = (char *)malloc(sizeof(char) * (i + 2));
    if (!new)
        return (NULL);
    i = 0;
    while (buffer && buffer[i] != '\n')
    {
        new[i] = buffer[i];
        i++;
    }
    if (buffer[i] == '\n')
    {   
        new[i] = buffer[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char    *ft_fill_line_buffer(int fd, char *str)
{
    char *buff;
    size_t buff_read;

    buff = malloc(sizeof(BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    buff_read = 1;
    while (!(ft_strchr(str,'\n')) && buff_read > 0)
    {
        buff_read = read(fd, buff, BUFFER_SIZE);
        if (buff_read == -1)
        {
            free(buff);
            buff = NULL;
            return (NULL);
        }
        buff[buff_read] = '\0';
        str = ft_strjoin(str, buff);
    }
    free(buff);
    return (str);
}

char    *get_next_line(int fd)
{
    static char *buffer;
    char *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(buffer);
        buffer = NULL;
        return (NULL);
    }
    buffer = ft_fill_line_buffer(fd, buffer);
    line = ft_set_line(buffer);
    return (line);
}