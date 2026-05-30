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
