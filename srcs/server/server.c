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


void	ft_stock_char(int signal)
{
	static char c[9];
	char character;
	static int i = 0;

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
		if(character == 0)
			ft_printf("\n");
		ft_printf("%c", character);
		i = 0;
	}
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, &ft_stock_char);
	signal(SIGUSR2, &ft_stock_char);
	while(1)
		pause();
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