#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;
	
	if (ptr == NULL)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*s;
	
	if (dest == NULL || src == NULL)
		return (NULL);
	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (len > 0)
	{
		*p = *s;
		p++;
		s++;
		len--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;
	
	if (dest == NULL || src == NULL)
		return (NULL);
	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	if (p > s)
	{
		while (len > 0)
		{
			p[len - 1] = s[len];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			p[i] = s[i];
			i++;
		}
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = ft_strlen(src);
	if (len == 0)
		return (i);
	if (len >= i + 1)
		ft_memcpy(dest, src, i + 1);
	else
	{
		ft_memcpy(dest, src, len - 1);
		dest[len - 1] = '\0';
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
    j = ft_strlen(dest);
	if (len <= j)
		return (i + j);
	if (i < (len - j))
		ft_memcpy((dest + j), src, (i + 1));
	else
	{
		ft_memcpy((dest + j), src, (len - j - 1));
		dest[len - 1] = '\0';
	}
	return (i + j);
}