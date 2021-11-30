#include "libft/libft.h"
#include "ft_printf.h"

#include <stdio.h>
int main(void)
{
	char p;
	int nbr;
	char *str = "Hello world";

	p = 'b';
	nbr = 7;
	str = "H";
	nbr = printf(" %x ", 0);
	printf("%d \n", nbr);
	nbr = ft_printf(" %x ", 0);
	ft_printf("%d \n", nbr);
}
