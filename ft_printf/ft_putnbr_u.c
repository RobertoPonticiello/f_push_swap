#include "ft_printf.h"

int	ft_print_unsigned_recursive(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n > 9)
		count += ft_print_unsigned_recursive(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	ft_putnbr_u(va_list x)
{
	unsigned int	n;

	n = va_arg(x, unsigned int);
	return (ft_print_unsigned_recursive(n));
}
