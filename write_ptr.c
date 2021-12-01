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

int	ft_printstring(char *s, int fd)
{
	int i;

	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	return (i);
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

int	ft_printnbr(long int n, int fd)
{
	char	pr;
	int		i;

	i = 0;
	if (n < 0)
	{
		i += write(fd, "-", 1);
		i += ft_printnbr(-n, fd);
	}
	else
	{
		if (n > 9)
			i+= ft_printnbr(n / 10, fd);
		pr = '0' + n % 10;
		i += write(fd, &pr, 1);
	}
	return (i);
}