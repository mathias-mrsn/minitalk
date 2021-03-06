/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:40:56 by mamaurai          #+#    #+#             */
/*   Updated: 2021/12/05 14:31:14 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	__count_signal__(int signal)
{
	static size_t	received = 0;

	if (signal == SIGUSR1)
		received += 1;
	return (received);
}

int	__kill__(int pid, int signal)
{
	static uint64_t	total_send = 0;

	if (kill(pid, signal) == __ERROR)
		return (__ERROR);
	if (SIGUSR1 == signal || SIGUSR2 == signal)
		total_send += 1;
	return (total_send);
}
