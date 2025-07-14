#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_va(va_list x)
{
	char	c;

	c = (char)va_arg(x, int);
	write(1, &c, 1);
	return (1);
}
