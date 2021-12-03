#include "../../includes/ft_printf.h"

void	printf_ft_unsigned_putnbr(unsigned int nb, char *base, t_options *options)
{
	if(nb >= printf_ft_strlen(base))
		printf_ft_unsigned_putnbr(nb / printf_ft_strlen(base), base, options);
	printf_ft_putchar(base[nb % printf_ft_strlen(base)], 1, options);
}

void printf_ft_print_addr(unsigned long addr, int first, t_options *options)
{
	char *base;

	base = "0123456789abcdef";

	if (first == 0)
		printf_ft_putstr("0x", -1, options);
	if (addr < 0)
	{
		return (printf_ft_print_addr(addr * -1, ++first, options));
	}
	if (addr >= 16)
	{
		printf_ft_print_addr(addr / 16, ++first, options);
		printf_ft_print_addr(addr % 16, ++first, options);
	}
	else
		printf_ft_putchar(base[addr % 16], 1, options);
}

void printf_ft_print_convert(t_options *options, t_argument *arg)
{
	if(options->conversion == 'd' || options->conversion == 'i')
			printf_ft_putnbr((int)arg->arg, 1, options);
	else if(options->conversion == 's')
		printf_ft_putstr(arg->arg_s, options->precision_value, options);
	else if(options->conversion == 'c')
		printf_ft_putchar(arg->arg_c, 1, options);
	else if(options->conversion == '%')
		printf_ft_putchar('%', 1, options);
	else if(options->conversion == 'u')
		printf_ft_unsigned_putnbr((unsigned int)arg->arg, decimal, options);
	else if(options->conversion == 'x')
		printf_ft_unsigned_putnbr((unsigned int)arg->arg, hexa, options);
	else if(options->conversion == 'X')
		printf_ft_unsigned_putnbr((unsigned int)arg->arg, HEXA, options);
	else if(options->conversion == 'p')
		printf_ft_print_addr((unsigned long)arg->arg, 0, options);
}

void	printf_ft_print_sign(t_options *options, t_argument *arg)
{
	if (printf_ft_is_charset(options->conversion, "diu"))
	{
		if (arg->arg < 0)
			printf_ft_putchar('-', 1, options);
		else if(options->flag_plus)
			printf_ft_putchar('+', 1, options);
		else if(options->flag_space)
			printf_ft_putchar(' ', 1, options);
	}
	else if (printf_ft_is_charset(options->conversion, "xX") && options->flag_hashtag && arg->arg)
	{
		if (options->conversion == 'x')
			printf_ft_putstr("0x", -1, options);
		if (options->conversion == 'X')
			printf_ft_putstr("0X", -1, options);
	}

}

void	printf_ft_print_hub(t_options *options, t_argument *arg)
{
	
	if(!options->flag_align)
		printf_ft_print_blank(options, arg);
	printf_ft_print_sign(options, arg);
	printf_ft_print_zero(options, arg);
	printf_ft_print_convert(options, arg);
	if(options->flag_align)
		printf_ft_print_blank(options, arg);
}