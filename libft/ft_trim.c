static int    ft_setcheck(char c, char const *set)
{
    int     i;

    i = 0;
    while(set[i])
    {
	if (set[i] == c)
	    return (1);
	i++;
    }
    return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
    char    *trim;
    size_t  start;
    size_t  end;

    start = 0;
    end = (ft_strlen(s1) - 1);
    if (end <= 0)
	return (NULL);
    while(start < end)
    {
	if (ft_setcheck(s1[start], set))
	    start++;
	else
	    break;
    }
    while(end > start)
    {
	if(ft_setcheck(s1[end], set))
	    end--;
	else
	    break;
    }
    trim = ft_substr(s1, start, (end - start + 1));
    return (trim);
}

static int  ft_digitscount(int n)
{
    int i;

    i = 0;
    if (n < 0)
    {
	n = n * (-1);
	i++;
    }
    while (n > 0)
    {
	i++;
	n = n / 10;
    }
    return (i);
}

char	*ft_itoa(int n)
{
    char    *str;
    size_t  i;

    i = ft_digitscount(n);
    if (n == 0)
	return (ft_strdup("0"));
    if (n == -2147483648)
	return (ft_strdup("-2147483648"));
    str = malloc((i + 1) * sizeof(char));
    if (!str)
	return (NULL);
    str[i] = '\0';
    i--;
    if (n < 0)
    {
	str[0] = '-';
	n = n * -1;
    }
    while (n > 0)
    {
	str[i] = (n % 10) + '0';
	n = n / 10;
	i--;
    }
    return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    size_t  len; 
    char *res;

    len = ft_strlen(s);
    res = malloc((len + 1) * sizeof(char));
    if (!res)
	return (NULL);
    i = 0;
    while (i < len)
    {
	res[i] = (*f)(i, s[i]);
	i++;
    }
    res[i] = 0;
    return (res);
}
