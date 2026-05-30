char	*ft_strchr(const char *s, int c)
{
    size_t     i;

    i = 0;
    while (s[i])
    {
	if (s[i] == (char)c)
	    return ((char *)&s[i]);
	else
	    i++;
    }
    if ((char)c == '\0')
	return ((char *)&s[i]);
    return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
    size_t     i;

    i = ft_strlen(s);
    while (i >= 0)
    {
	if (s[i] == (char)c)
	    return ((char *)&s[i]);
	else
	    i--;
    }
    return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t     i;

    i = 0;
    while ((s1[i] || s2[i]) && i < n)
    {
	if (s1[i] != s2[i])
	    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
	    i++;
    }
    return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t	    i;
    unsigned char   *ptr;
    unsigned char   cc;

    i = 0;
    ptr = (unsigned char *)s;
    cc = (unsigned char)c;
    while (i < n)
    {
	if (ptr[i] == cc)
	    return ((void *)&ptr[i]);
	i++;
    }
    return (NULL);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t	    i;
    unsigned char   *str1;
    unsigned char   *str2;

    i = 0;
    str1 = (unsigned char *)s1;
    str2 = (unsigned char *)s2;
    while (i < n)
    {
	if (str1[i] != str2[i])
	    return (str1[i] - str2[i]);
	else
	    i++;
    }
    return (0);
}
