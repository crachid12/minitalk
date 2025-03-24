/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:07:51 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 21:38:45 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static void	send_signal(int pid, char c)
{
	int	bit;

	bit = 8;
	while (--bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf(2, "Error: kill failed\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf(2, "Error: kill failed\n");
				exit(1);
			}
		}
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid_server;
	int	i;

	i = 0;
	if (argc != 3)
		return (ft_printf(2, "Error \nUsage: ./client <PID> <message>\n"), 1);
	if (!is_number(argv[1]))
		return (ft_printf(2, "Error: invalid PID\n"), 1);
	pid_server = ft_atoi(argv[1]);
	kill(pid_server, 0);
	if (pid_server <= 0 || errno == ESRCH)
		return (ft_printf(2, "Error: invalid PID\n"), 1);
	while (argv[2][i])
	{
		send_signal(pid_server, argv[2][i]);
		i++;
	}
	send_signal(pid_server, '\0');
	return (0);
}
