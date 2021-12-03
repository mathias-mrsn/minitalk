#include "../includes/libft.h"

void ft_putaddr_fd(void *addr, int fd)
{
	size_t address;
	size_t div;

	div = 16;
	address = (size_t)addr;
	write(fd, "0x", 2);
	while (address / div > 15)
		div *= 16;
	while (div > 0)
	{
		write(fd, &hexa[address / div], 1);
		address %= div;
		div /= 16;
	}
}

void ft_putaddr(void *addr)
{
	ft_putaddr_fd(addr, 1);
}
