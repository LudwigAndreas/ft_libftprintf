#include "ft_printf.h"

static int	ft_intlen(long int nbr)
{
	int len;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int d;
	unsigned int u;
	char c;
	char *s;
	int i;
	void *p;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*(format) != '%')
		{
			write(1, format, 1);
			i++;
		}
		else
		{
			if (*(format + 1) == 's')
			{
				s = va_arg(ap, char *);
				if (s)
				{
					ft_putstr_fd(s, 1);
					i += ft_strlen(s);
				}
				else
				{
					ft_putstr_fd("(null)", 1);
					i += 6;
				}
			}
			else if (*(format + 1) == 'd' || *(format + 1) == 'i')
			{
				d = va_arg(ap, int);
				ft_putnbr_fd(d, 1);
				i += ft_intlen(d);
			}
			else if (*(format + 1) == '%')
			{
				write(1, "%", 1);
				i++;
			}
			else if (*(format + 1) == 'c')
			{
				c = (char) va_arg(ap, int);
				write(1, &c, 1);
				i++;
			}
			else if (*(format + 1) == 'p')
			{
				p = va_arg(ap, void *);
				i += write_ptr(p);
			}
			else if (*(format + 1) == 'u')
			{
				u = va_arg(ap, unsigned int);
				ft_putnbr_fd(u, 1);
				i += ft_intlen((unsigned int) u);
			}
			else if (*(format + 1) == 'x')
			{
				d = va_arg(ap, int);
				i += ft_puthexnbr(d, 'x');
			}
			else if (*(format + 1) == 'X')
			{
				d = va_arg(ap, int);
				i += ft_puthexnbr(d, 'X');
			}
			format++;
		}
		format++;
	}
	return (i);
}
