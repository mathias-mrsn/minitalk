#include "minitalk.h"

static void	char_to_binary(int pid, const char c)
{
	int	index;

	index = 7;
	while (index > -1)
	{
		if (1 & c >> index)
		{
			if (__kill__(pid, SIGUSR2) == -1)
				exit(0);
		}
		else
		{
			if (__kill__(pid, SIGUSR1) == -1)
				exit(0);
		}
		index--;
		signal(SIGUSR1, (void *)__count_signal__);
		pause();
		usleep(50);
	}
}

static void	encoding_str(int pid, char *str)
{
	int index;

	index = 0;
	while (str[index])
	{
		char_to_binary(pid, str[index]);
		index++;
	}
	char_to_binary(pid, '\0');
}

static int	check_params(int argc, char **argv)
{
	uint32_t	pid;

	if (argc < 2)
		return (ft_printf("minitalk : arguments missing"), -1);
	if (argc > 3)
		return (ft_printf("minitalk : too many arguments"), -1);
	pid = ft_atoi(argv[1]);
	if(kill(pid, 0) == -1)
		return (ft_printf("minitalk : invalid PID"), -1);
	return (1);
}

int main(int argc, char **argv)
{
	uint32_t	pid;
	char		*str;

	if (-1 == check_params(argc, argv))
		return (1);
	pid = ft_atoi(argv[1]);
	if (argc == 2)
	{
		str = get_next_line(0);
		while (str)
		{
			encoding_str(pid, str);
			free(str);
			str = get_next_line(0);
			usleep(1000);
		}
	}
	else
		encoding_str(pid, argv[2]);
	ft_printf("You lost %d signals", __kill__(0, 0) - __count_signal__(0));
	return (0);
}