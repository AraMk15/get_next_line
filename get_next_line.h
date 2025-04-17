#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE  42

# include <unistd.h>
# include <fcntl.h>

void ft_putchr(int c);
size_t ft_strlen(const char *str);
void ft_putstr(const char *str);
char *ft_strchr(const char *str, int c);
char *ft_strlcpy(char *dest, const char *src, size_t destsize);
char *ft_strjoin(const char *s1, const char *s2);
char *ft_strdup(const char *s);

#endif