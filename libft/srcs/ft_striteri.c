#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int index;

	if (!s)
		return ;
	index = -1;
	while(s[++index])
		(*f)(index, &s[index]);
}