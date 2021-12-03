#include "../includes/libft.h"

void ft_putnstr_fd(char *str, int fd, size_t len)
{
	if (!str)
		return;
	while (*str && len--)
		ft_putchar_fd(*str++, fd);
}

void ft_putnstr(char *str, size_t len)
{
	ft_putnstr_fd(str, 1, len);
}