#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	ft_bzero(void *ptr, size_t len)
{
	unsigned char	*p;
	size_t		i;

   	if (ptr == NULL)
		return;
	p = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		p[i] = '\0';
		i++;
	}
}