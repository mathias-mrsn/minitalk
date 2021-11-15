#include "../../includes/minitalk.h"

int	ft_atoi_binary(char c[9])
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while(i < 8)
	{
		res *= 2;
		res += c[i] - 48;
		i++;
	}
	return (res);
}


void	ft_stock_char(int signal, siginfo_t *siginfo, void *data)
{
	static char c[9];
	static int	start = 0;
	char character;
	static int i = 0;

	if(i == 0)
		ft_memset(c, '\0', 9);
	if(start == 0)
	{
		start = 1;
		ft_printf("%d --> ", siginfo->si_pid);
	}
	if(i < 8)
	{
		if(signal == SIGUSR1)
			c[i] = '0';
		else
			c[i] = '1';
		i++;
	}
	if(i == 8)
	{
		c[8] = '\0';
		character = ft_atoi_binary(c);
		ft_printf("%c", character);
		if(character == 0)
		{
			ft_printf("\n");
			start = 0;
		}
		i = 0;
	}
}

int	main(void)
{
	struct sigaction sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = ft_stock_char;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;


	printf("|------------PID : %d------------|\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
	printf("END");
	return (0);
}

/*----------------------------------------------------------------


signal() 	: Get a signal and execute a function with in param his signal (signal, function)

kill()		: Sent a signal to a pid (pid, signal)

getpid()	: Get the pid of the server program

pause()		: Suspends the program until a singal arrives (void)

usleep()	: Suspends the program during n microseconds (useconds_t)

exit()		: Exit of the program

sigaction()	: 


SIGUSR 1, 2 :

*/