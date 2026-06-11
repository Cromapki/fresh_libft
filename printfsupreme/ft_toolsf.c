#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_ptnbr_bs(unsigned long n, char *base)
{
	unsigned long	base_len;
	int				cnt;

	base_len = ft_strlen(base);
	cnt = 0;
	if (n >= base_len)
		cnt += ft_ptnbr_bs((n / base_len), base);
	cnt += ft_putchar(base[n % base_len]);
	cnt++;
	return (cnt);
}

int	ft_putnbr(int n)
{
	int	cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		cnt++;
		n = -n;
	}
	if (n >= 10)
		cnt += ft_putnbr(n / 10);
	cnt += ft_putchar((n % 10) + '0');
	cnt++;
	return (cnt);
}

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		s = "(null)";
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_pntr_prnt(va_list *ap)
{
	unsigned long	addrs;
	int				cnt;

	addrs = (unsigned long)va_arg(*ap, void *);
	cnt = ft_putstr("0x");
	cnt += ft_ptnbr_bs(addrs, "0123456789abcdef");
	return (cnt);
}
	
