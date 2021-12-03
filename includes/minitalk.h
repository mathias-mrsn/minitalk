#ifndef MINITALK_H
#define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../libft/includes/libft.h"

/*	CLIENT	*/

int __count_signal__(int signal);
int	__kill__(int pid, int signal);

#endif