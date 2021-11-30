#include "ft_printf.h"

int static	is_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 1;
		while (base[j])
		{
			if (base[i] == base[j + i] || base[i] == '+' || base[i] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void (int nbr, char *base)
{
	int	base_size;

	base_size = is_base(base);
	if (base_size > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putnbr_base(nbr / base_size, base);
			write(1, &base[nbr % base_size], 1);
		}
		else if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_base(-nbr, base);
		}
		else
		{
			if (nbr > base_size - 1)
				ft_putnbr_base(nbr / base_size, base);
			write(1, base + (nbr % base_size), 1);
		}
	}
}
