#include "../../includes/minitalk.h"

void	print(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("0");
	else
		ft_printf("1");
}

int	main(void)
{
	printf("PID : %d\n", getpid());
	signal(SIGUSR1, &print);
	signal(SIGUSR2, &print);
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