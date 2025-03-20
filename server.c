/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:07:51 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/20 12:33:34 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"

static pid_t    client_pid;

void handle_signal(int signal, siginfo_t *info, void *context)
{
	static int bit;
	static char     c;

	(void)context;
	 if (client_pid == 0)
        client_pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8 && client_pid == info->si_pid)
	{
		if (c == '\0')
		{
			client_pid = 0;
		}
		write(1, &c, 1);
		// kill(info->si_pid, SIGUSR1);
		c = 0;
		bit = 0;
	}
}

int main(void)
{
	struct sigaction sa;
	
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return 0;
}