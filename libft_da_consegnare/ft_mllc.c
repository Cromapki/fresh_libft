#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && ((i + j) < len))
			{
				if (to_find[j + 1] == '\0')
					return ((char *)&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*temp;

	if (n != 0 && size != 0 && n > SIZE_MAX / size)
		return (NULL);
	temp = malloc(n * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, (n * size));
	return (temp);
}

char	*ft_strdup(const char *s)
{
	char	*ss;
	size_t	len;

	len = ft_strlen(s);
	ss = malloc(len + 1);
	if (!ss)
		return (NULL);
	ft_memcpy(ss, s, (len + 1));
	return (ss);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;
	size_t			slen;

	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	else if (len > (slen - start))
		len = slen - start;
	i = 0;
	ss = malloc(len + 1);
	if (!ss)
		return (NULL);
	while (i < len && s[start])
	{
		ss[i] = s[start];
		i++;
		start++;
	}
	ss[i] = '\0';
	return (ss);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	dest = malloc(i + j + 1);
	if (!dest)
		return (NULL);
	k = 0;
	while (k < i)
	{
		dest[k] = s1[k];
		k++;
	}
	k = 0;
	while (k < j)
	{
		dest[k + i] = s2[k];
		k++;
	}
	dest[k + i] = '\0';
	return (dest);
}
