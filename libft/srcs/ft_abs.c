#include "../includes/libft.h"

long	ft_abs(long x)
{
	if(x < 0)
		return (x * -1);
	return (x);
}