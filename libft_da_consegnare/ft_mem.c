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

static void	ft_memmove_back(unsigned char *p, unsigned char *s, size_t len)
{
	while (len > 0)
	{
		len--;
		p[len] = s[len];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*p;
	unsigned char		*s;

	if (dest == NULL || src == NULL)
		return (NULL);
	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (p > s)
		ft_memmove_back(p, s, len);
	else
	{
		while (len > 0)
		{
			*p = *s;
			p++;
			s++;
			len--;
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
