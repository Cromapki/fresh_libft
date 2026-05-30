static size_t	ft_wordcount(const char *s, char c)
{
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	ft_free(char **splt, size_t j)
{
	while (j > 0)
	{
		j--;
		free(splt[j]);
	}
	free (splt);
}

static int	ft_fill(char **splt, const char *s, char c)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			splt[j] = ft_substr(s, i, ft_wordlen((s + i), c));
			if (!splt[j])
				return (0);
			i = i + ft_wordlen((s + i), c);
			j++;
		}
	}
	splt[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**splt;

	splt = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!splt)
		return (NULL);
	if (!ft_fill(splt, s, c))
	{
		ft_free(splt, ft_wordcount(s, c));
		return (NULL);
	}
	return (splt);
}
