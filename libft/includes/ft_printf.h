#ifndef	printf_ft_PRINTF_H
# define printf_ft_PRINTF_H

# define hexa "0123456789abcdef"
# define HEXA "0123456789ABCDEF"
# define decimal "0123456789"
# define CONV_POSSIBLE "cspdiuxX%"
# define FLAGS "+ #-0"

# include <stdarg.h>
# include <unistd.h>
#include <stdlib.h>

typedef	struct 	s_options
{
	char	conversion;

	int		flag_plus;
	int		flag_space;
	int		flag_hashtag;

	int		flag_dot;
	int		flag_zero;
	int		flag_align;
	
	int		precision_value;
	int		width;
	int		arg_length;
	int		printed_length;
}				t_options;

typedef	struct s_argument
{
	char		arg_c;
	char		*arg_s;
	long long	arg;
	char 		*base_used;
}				t_argument;

size_t 	printf_ft_strlen(const char *str);
int			printf_ft_nbrlen_base_unsigned(unsigned long n, char *base);
int		ft_printf(const char *str, ...);
int		printf_ft_is_charset(char c, char *set);
void	printf_ft_procesing(t_options *options);
int		printf_ft_nbrlen_base(long long n, char *base);
void	printf_ft_putnbr(int n, int fd, t_options *options);
void	printf_ft_tester(t_options *options, t_argument *arg);
void	printf_ft_putchar(char c, int fd, t_options *options);
int		printf_ft_get_width(const char **str, va_list settings);
void	printf_ft_putstr(char *str, int nb, t_options *options);
void	printf_ft_print_hub(t_options *options, t_argument *arg);
int		printf_ft_get_flags(t_options *options, const char **str);
void	printf_ft_parse_init(t_argument *arg, t_options *options);
void	printf_ft_print_sign(t_options *options, t_argument *arg);
void	printf_ft_print_zero(t_options *options, t_argument *arg);
void	printf_ft_print_blank(t_options *options, t_argument *arg);
int		printf_ft_get_convert(t_options *options, const char **str);
void 	printf_ft_print_convert(t_options *options, t_argument *arg);
void	printf_ft_get_arg_length(t_options *options, t_argument 	*arg);
void 	printf_ft_print_addr(unsigned long addr, int first, t_options *options);
void	printf_ft_get_arg(t_options *options, va_list settings, t_argument *arg);
void	printf_ft_unsigned_putnbr(unsigned int nb, char *base, t_options *options);
void	printf_ft_print_blank_char(t_options *options, int *blank);
void	printf_ft_print_blank_digit(t_options *options, t_argument *arg, int *blank);
void	printf_ft_get_precision(t_options *options, const char **str, va_list settings);
void	printf_ft_parse_hub(t_options *options, const char **str, va_list settings, t_argument *arg);

#endif