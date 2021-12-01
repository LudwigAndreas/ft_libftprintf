#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	write_ptr(void *p);
int	ft_puthexnbr(int nbr, char x);
int	ft_printstring(char *s, int fd);
int	ft_printnbr(long int n, int fd);

#endif
