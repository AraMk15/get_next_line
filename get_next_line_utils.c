

unsigned int ft_strlen(const char *str)
{
    unsigned int    i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
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

char    *ft_strlcpy(char *dest, const char *src, unsigned long long destsize)
{
    unsigned long long  i;

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
    unsigned long long len;

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
    unsigned long long  len;
    unsigned long long  i;

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

