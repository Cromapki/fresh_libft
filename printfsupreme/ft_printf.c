#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	chk_conversion(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'u')
		return (ft_ptnbr_bs(va_arg(*ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_ptnbr_bs(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_ptnbr_bs(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'p')
		return (pntr_prnt(ap));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	i;
	int	res;

	va_start(ap, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			res += chk_conversion(format[i], &ap);
		}
		else
			res += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (res);
}
