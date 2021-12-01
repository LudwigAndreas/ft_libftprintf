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
	nbr = printf("Hello world!");
//	printf("%");
	printf("%d \n", nbr);
	nbr = ft_printf("Hello world!");
	ft_printf("%d \n", nbr);
}
