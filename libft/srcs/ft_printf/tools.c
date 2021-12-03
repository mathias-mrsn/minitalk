#include "../../includes/ft_printf.h"

int	printf_ft_is_charset(char c, char *set)
{
	while(*set)
	{
		if(c == *set)
			return (1);
		set++;
	}
	return (0);
}

int			printf_ft_nbrlen_base_unsigned(unsigned long n, char *base)
{
	int			i;
	int	base_len;

	base_len = printf_ft_strlen(base);
	i = 1;
	if(base_len <= 1)
		return (0);
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

int			printf_ft_nbrlen_base(long long n, char *base)
{
	int			i;
	long long	base_len;

	// printf("%lu", n);
	base_len = printf_ft_strlen(base);
	i = 1;
	if(base_len <= 1)
		return (0);
	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

void	printf_ft_putchar(char c, int fd, t_options *options)
{
	write(fd, &c, 1);
	options->printed_length++;
}