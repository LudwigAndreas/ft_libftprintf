#include "ft_printf.h"

static char hex_digit(int v, char x)
{
	if (v >= 0 && v < 10)
		return '0' + v;
	else
	{
		if (x == 'x')
			return 'a' + v - 10;
		return 'A' + v - 10;
	}
}

int	ft_puthexnbr(int nbr, char x)
{
	int i;
	int len;

	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	len = 0;
	i = (sizeof(nbr) << 3) - 4;
	while (((nbr >> i) & 0xf) == 0)
		i -= 4;
	while (i >= 0)
	{
		ft_putchar_fd(hex_digit((nbr >> i) & 0xf, x), 1);
		len++;
		i -= 4;
	}
	return (len);
}


int	write_ptr(void *p0)
{
	int i;
	int len;
	uintptr_t p = (uintptr_t)p0;

	 if (p0) {
		len = 2;
		i = (sizeof(p) << 3) - 4;
		write(1, "0x", 2);
		while (((p >> i) & 0xf) == 0)
			i -= 4;
		while (i >= 0)
		{
			ft_putchar_fd(hex_digit((p >> i) & 0xf, 'x'), 1);
			len ++;
			i -= 4;
		}
		 return (len);
	 }
	else
		ft_putstr_fd("0x0", 1);
	return (3);
}
