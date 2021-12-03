#include "../../includes/ft_printf.h"

void	printf_ft_putnbr(int n, int fd, t_options *options)
{
	unsigned int nb;

	if(n < 0)
		nb = -n;
	else
		nb = n;
	if(nb > 9)
		printf_ft_putnbr(nb / 10, fd, options);
	printf_ft_putchar(nb % 10 + 48, fd, options);
}

size_t printf_ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


void	printf_ft_putstr(char *str, int nb, t_options *options)
{
	if(nb == 0)
		return;
	while(*str && nb--)
		printf_ft_putchar(*str++, 1, options);
}