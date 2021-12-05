/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:40:41 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 14:37:50 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#define __WAITING_TIME__ 50

static void	ft_exit(int signal)
{
	__printf("\n\\----------------END----------------/\n");
	exit(__SUCCESS);
}

static void	ft_stock_char(int signal, siginfo_t *siginfo, void *data)
{
	static unsigned char	c = 0;
	static int32_t			i = 7;
	static uint8_t			start = 0;

	(void)data;
	usleep(__WAITING_TIME__);
	kill(siginfo->si_pid, SIGUSR1);
	if (0 == start && ++start)
		__printf("%d --> ", siginfo->si_pid);
	if (i > -1)
		c |= ((signal == SIGUSR2) << i);
	i--;
	if (i == -1)
	{
		__printf("%c", c);
		if (0 == c)
		{
			__printf("\n");
			start = 0;
		}
		c = '\0';
		i = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	__memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_sigaction = ft_stock_char;
	sa.sa_flags = SA_SIGINFO;
	__printf("/------------PID : %d------------\\\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, &ft_exit);
	while (1)
		pause();
	return (__SUCCESS);
}
