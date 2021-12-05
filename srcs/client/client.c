/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:42:37 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 14:31:41 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	char_to_binary(int pid, const char c)
{
	int	index;

	index = 7;
	while (index > -1)
	{
		if (1 & c >> index)
		{
			if (__kill__(pid, SIGUSR2) == __ERROR)
				exit(__FAILURE);
		}
		else
		{
			if (__kill__(pid, SIGUSR1) == __ERROR)
				exit(__FAILURE);
		}
		index--;
		signal(SIGUSR1, (void *)__count_signal__);
		pause();
		usleep(50);
	}
}

static void	encoding_str(int pid, char *str)
{
	int	index;

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
		return (__printf("minitalk : arguments missing\n"), __ERROR);
	if (argc > 3)
		return (__printf("minitalk : too many arguments\n"), __ERROR);
	pid = __atoi(argv[1]);
	if (kill(pid, 0) == __ERROR)
		return (__printf("minitalk : invalid PID\n"), __ERROR);
	return (__SUCCESS);
}

int	main(int argc, char **argv)
{
	uint32_t	pid;
	char		*str;

	if (__ERROR == check_params(argc, argv))
		return (1);
	pid = __atoi(argv[1]);
	if (argc == 2)
	{
		str = __gnl(__STDIN);
		while (str)
		{
			encoding_str(pid, str);
			free(str);
			str = __gnl(__STDIN);
			usleep(1000);
		}
	}
	else
		encoding_str(pid, argv[2]);
	__printf("You lost %d signals", __kill__(0, 0) - __count_signal__(0));
	return (__SUCCESS);
}
