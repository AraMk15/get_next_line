#include "get_next_line.h"

void    ft_putchr(int c)
{
    write(1, &c, 1);
}

size_t ft_strlen(const char *str)
{
    size_t    i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

void    ft_putstr(const char *str)
{
    size_t  len;
    size_t  i;

    if (!str)
        return;
    len = ft_strlen(str);
    while (i < len - 1 && str[i] != '\0')
    {
        ft_putchr(str[i]);
        i++;
    }
}

char    *ft_strchr(const char *str, int c)
{
    unsigned  int   i;

    if (c == '\0')
        return (char *)(str);
    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (str[i]);
        i++;
    }
    return (0);
}

char    *ft_strlcpy(char *dest, const char *src, size_t destsize)
{
    size_t  i;

    if (!dest && !src)
        return (ft_strlen(src));
    if (destsize == 0)
        return (ft_strlen(src));
    i = 0;
    while (i < destsize - 1 && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    char *str;
    size_t len;

    if (!s1 || !s2)
        return (NULL);
    len = ft_streln(s1) + ft_strlen(s2);
    if (!str)
        return (NULL);
    ft_strlcpy(str, s1, len);
    ft_strlcpy(str, s2, len);
    return (str);
}

char    *ft_strdup(const char *s)
{
    char *str;
    size_t  len;
    size_t  i;

    if (!s || !str)
        return (NULL);
    len = ft_strlen(s);
    str = (char *)malloc(len + 1);
    i = 0;
    while (i < len - 1 && s[i] != '\0')
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}