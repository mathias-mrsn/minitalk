#include "../includes/libft.h"

long ft_random(int len_max)
{
	int fd;
	int i;
	long res;
	char str[7];

	res = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (0);
	if (read(fd, str, 9))
	{
		str[6] = '\0';
		i = 6;
		while (--i > 0)
		{
			res *= 10;
			res += str[i];
		}
	}
	close(fd);
	if (res < 0)
		res *= -1;
	return (res % len_max);
}