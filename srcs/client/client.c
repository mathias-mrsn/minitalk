#include "../../includes/minitalk.h"

void	ft_char_to_binary(int pid, const char c)
{
	int	index;

	index = 7;
	while(index > -1)
	{
		if(1 & c >> index)
		{
			if(kill(pid, SIGUSR2) == -1)
				exit(0);
		}
		else
		{
			if(kill(pid, SIGUSR1) == -1)
				exit(0);
		}
		usleep(50);
		index--;
	}
}

void	ft_encoding_str(int pid, char *str)
{
	int	index;

	index = 0;
	while(str[index])
	{
		ft_char_to_binary(pid, str[index]);
		index++;
	}
	ft_char_to_binary(pid, '\0');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc < 3)
		ft_printf("minitalk : arguments missing");
	if (argc > 3)
		ft_printf("minitalk : too many arguments");
	pid = ft_atoi(argv[1]);
	ft_encoding_str(pid, argv[2]);
	return(0);
}