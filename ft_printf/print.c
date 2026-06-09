#include "libft.h"
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_bs(unsigned long n, char *base)
{
	unsigned long	base_len;
	
	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_bs(n / base_len, base);
	ft_putchar(base[n % base_len]);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		s = "null";
	
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	pointer_print(va_list *args)
{
	unsigned long	address;

	address = (unsigned long)va_arg(*args, void *);
	ft_putstr("0x");
	ft_putnbr_bs(address, "0123456789abcdef");
}

void	check_conversion(char c, va_list *args)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		ft_putstr(va_arg(*args, char *));
	else if (c == 'u')
		ft_putnbr_bs(va_arg(*args, unsigned int), "0123456789");
	else if (c == 'x')
		ft_putnbr_bs(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_putnbr_bs(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar('%');
	else if (c == 'p')
		pointer_print(args);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	i;

	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			check_conversion(format[i], &args);
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (i);
}

int main(void)
{
	char str[] = "Ciao mi chiamo %s, ho %d anni";
	char name[] = "Marco";
	int age = 21;

	ft_printf(str, name, age);
	ft_putchar('\n');
	return (0);
}
