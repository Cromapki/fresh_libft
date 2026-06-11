#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// - - - - - ft_printf.c - - - - -
int		ft_printf(const char *format, ...);
int		ft_chk_conversion(char c, va_list *ap);
size_t	ft_strlen(const char *s);
// - - - - - ft_toolsf.c - - - - -
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_ptnbr_bs(unsigned long n, char *base);
int	ft_pntr_prnt(va_list *ap);

#endif
