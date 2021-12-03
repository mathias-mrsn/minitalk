#include "../includes/libft.h"

void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
}
