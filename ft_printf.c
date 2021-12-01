#include "ft_printf.h"

int	doprint(const char *format, va_list *ap)
{
	int i;
	long int d;
	char c;
	char *s;
	void *p;

	i = 0;
	while (*format)
	{
		if (*(format) != '%')
			i += write(1, format, 1);
		else
		{
			if (*(format + 1) == 's')
			{
				s = va_arg(*ap, char *);
				if (s)
					i += ft_printstring(s, 1);
				else
					i += ft_printstring("(null)", 1);
			}
			else if (*(format + 1) == 'd' || *(format + 1) == 'i')
			{
				d = va_arg(*ap, int);
				i += ft_printnbr(d, 1);
			}
			else if (*(format + 1) == '%')
				i += write(1, "%", 1);
			else if (*(format + 1) == 'c')
			{
				c = (char) va_arg(*ap, int);
				i += write(1, &c, 1);
			}
			else if (*(format + 1) == 'p')
			{
				p = va_arg(*ap, void *);
				i += write_ptr(p);
			}
			else if (*(format + 1) == 'u')
			{
				d = va_arg(*ap, unsigned int);
				i += ft_printnbr(d, 1);
			}
			else if (*(format + 1) == 'x' || *(format + 1) == 'X')
			{
				d = va_arg(*ap, int);
				i += ft_puthexnbr(d, *(format + 1));
			}
			format++;
		}
		format++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int i;

	va_start(ap, format);
	i = doprint(format, &ap);
	va_end(ap);
	return (i);
}
//int	ft_printf(const char *format, ...)
//{
//	va_list ap;
//	int d;
//	unsigned int u;
//	char c;
//	char *s;
//	int i;
//	void *p;
//
//	i = 0;
//	va_start(ap, format);
//	while (*format)
//	{
//		if (*(format) != '%')
//		{
//			write(1, format, 1);
//			i++;
//		}
//		else
//		{
//			if (*(format + 1) == 's')
//			{
//				s = va_arg(ap, char *);
//				if (s)
//				{
//					ft_putstr_fd(s, 1);
//					i += ft_strlen(s);
//				}
//				else
//				{
//					ft_putstr_fd("(null)", 1);
//					i += 6;
//				}
//			}
//			else if (*(format + 1) == 'd' || *(format + 1) == 'i')
//			{
//				d = va_arg(ap, int);
//				ft_putnbr_fd(d, 1);
//				i += ft_intlen(d);
//			}
//			else if (*(format + 1) == '%')
//			{
//				write(1, "%", 1);
//				i++;
//			}
//			else if (*(format + 1) == 'c')
//			{
//				c = (char) va_arg(ap, int);
//				write(1, &c, 1);
//				i++;
//			}
//			else if (*(format + 1) == 'p')
//			{
//				p = va_arg(ap, void *);
//				i += write_ptr(p);
//			}
//			else if (*(format + 1) == 'u')
//			{
//				u = va_arg(ap, unsigned int);
//				ft_putnbr_fd(u, 1);
//				i += ft_intlen((unsigned int) u);
//			}
//			else if (*(format + 1) == 'x')
//			{
//				d = va_arg(ap, int);
//				i += ft_puthexnbr(d, 'x');
//			}
//			else if (*(format + 1) == 'X')
//			{
//				d = va_arg(ap, int);
//				i += ft_puthexnbr(d, 'X');
//			}
//			format++;
//		}
//		format++;
//	}
//	return (i);
//}
