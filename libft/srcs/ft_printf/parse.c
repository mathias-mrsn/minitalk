#include "../../includes/ft_printf.h"

void	printf_ft_parse_init(t_argument *arg, t_options *options)
{
	options->precision_value = -1;
	options->conversion = 0;
	options->flag_plus = 0;
	options->flag_space = 0;
	options->flag_hashtag = 0;
	options->flag_dot = 0;
	options->flag_zero = 0;
	options->flag_align = 0;
	options->width = 0;
	options->arg_length = 0;
	arg->arg_c = 0;
	arg->arg_s = 0;
	arg->arg = 0;
	arg->base_used = 0;
}

void	printf_ft_procesing(t_options *options)
{
	if((options->conversion != 'x' && options->conversion != 'X'))
		options->flag_hashtag = 0;
	if((options->conversion != 'd' && options->conversion != 'i'))
		options->flag_space = 0;
	if(!(options->conversion == 'd' || options->conversion == 'i'))
		options->flag_plus = 0;
	if(options->flag_plus && options->flag_space)
		options->flag_space = 0;
	if(options->flag_zero && options->flag_align)
		options->flag_zero = 0;
}

void	printf_ft_get_arg_length(t_options *options, t_argument 	*arg)
{
	if(printf_ft_is_charset(options->conversion, "diu"))
		arg->base_used = decimal;
	else if(printf_ft_is_charset(options->conversion, "xp"))
		arg->base_used = hexa;
	else if(options->conversion == 'X')
		arg->base_used = HEXA;

	if(printf_ft_is_charset(options->conversion, "diuxXp"))
		if(options->conversion == 'p' && (long)arg->arg < 0)
			options->arg_length = (printf_ft_nbrlen_base_unsigned(arg->arg, arg->base_used));
		else if(arg->arg < 0)
			options->arg_length = (printf_ft_nbrlen_base(-1 * arg->arg, arg->base_used));
		else
			options->arg_length = printf_ft_nbrlen_base(arg->arg, arg->base_used);
	else if(options->conversion == 's')
		options->arg_length = printf_ft_strlen(arg->arg_s);
	else
		options->arg_length = 1;

}

void	printf_ft_get_arg(t_options *options, va_list settings, t_argument 	*arg)
{
	if (printf_ft_is_charset(options->conversion, "di"))
		arg->arg = va_arg(settings, int);
	else if(printf_ft_is_charset(options->conversion, "uxX"))
		arg->arg = va_arg(settings, unsigned int);
	else if(printf_ft_is_charset(options->conversion, "p"))
		arg->arg = va_arg(settings, unsigned long);
	else if(printf_ft_is_charset(options->conversion, "c"))
		arg->arg_c = va_arg(settings, int);
	else if(printf_ft_is_charset(options->conversion, "%"))
		arg->arg_c = '%';
	else
		arg->arg_s = va_arg(settings, char *);
	if(arg->arg_s == NULL && options->conversion == 's')
		arg->arg_s = "(null)";
	printf_ft_get_arg_length(options, arg);
}

void	printf_ft_parse_hub(t_options *options, const char **str, va_list settings, t_argument *arg)
{
	printf_ft_parse_init(arg, options);
	printf_ft_get_flags(options, str);
	options->width = printf_ft_get_width(str, settings);
	printf_ft_get_precision(options, str, settings);
	printf_ft_get_convert(options, str);
	printf_ft_procesing(options);
	printf_ft_get_arg(options, settings, arg);
}