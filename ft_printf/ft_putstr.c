#include "ft_printf.h"

int	ft_putstr(char	*s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstr_va(va_list x)
{
	int		i;
	char	*s;

	i = 0;
	s = va_arg(x, char *);
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
