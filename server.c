/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:07:51 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 21:40:42 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_client_pid;

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	c;

	(void)context;
	if (g_client_pid == 0)
		g_client_pid = info->si_pid;
	if (signal == SIGUSR1)
		c |= (1 << (7 - bit));
	bit++;
	if (bit == 8 && g_client_pid == info->si_pid)
	{
		if (c == '\0')
		{
			g_client_pid = 0;
		}
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf(1, "Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf(2, "SIGUSR1 Error\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf(2, "SIGUSR2 Error\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
