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

char    *ft_strjoin(const char *s1, const char *s2)
{
    char *str;
    unsigned int i;
    unsigned int j;
    unsigned int k;

    if (!s1 && !s2)
        return (char *)(NULL);
    i = ft_strlen(s1);
    j = 0;
    while (j <= i && s1[j] != '\0')
    {
        str[j] = s1[j];
        j++;
    }
    i = ft_strlen(s2);
    k = 0; 
    while (j <= i && s2[j] != '\0')
    {
        str[j] = s2[k];
        j++;
        k++;
    }
    str[j] = '\0';
}

