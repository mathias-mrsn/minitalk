#include "minitalk.h"

static void ft_exit(int signal)
{
	ft_printf("\n\\----------------END----------------/\n");
	exit(0);
}

static void ft_stock_char(int signal, siginfo_t *siginfo, void *data)
{
	static unsigned char	c = 0;
	static int32_t			i = 7;
	static uint8_t			start = 0;

	(void)data;
	usleep(50);
	kill(siginfo->si_pid, SIGUSR1);
	if (0 == start && ++start)
		ft_printf("%d --> ", siginfo->si_pid);
	if (i > -1)
		c |= ((signal == SIGUSR2) << i);
	i--;
	if (i == -1)
	{
		ft_printf("%c", c);
		if (0 == c)
		{
			printf("\n");
			start = 0;
		}
		c = '\0';
		i = 7;
	}
}

int main(void)
{
	struct sigaction sa;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = ft_stock_char;
	sa.sa_flags = SA_SIGINFO;

	ft_printf("/------------PID : %d------------\\\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, &ft_exit);
	while (1)
		pause();
	return (0);
}
