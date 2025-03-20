/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:07:51 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/20 13:21:05 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
} 

void send_signal(int pid, char c)
{
	int bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(100);
		bit--;
	}
}

// void handle_ack(int sig) {
	// static int received = 0;

	// if (sig == SIGUSR1)
	//     ++received;
	// else
	// {
	//     ft_putnbr(received);
	//     ft_putchar('\n');
	//     exit(0);
	// }
	// ft_printf("signal recu avec succes %d", sig);
// 	(void)sig;
// }

int main(int argc, char **argv)
{
	int pid_server;
	int i;

	i = 0;
	if(argc != 3)
	{
		ft_printf("Error \nUsage: ./client <PID> <message>\n");
		return (1);
	}
	if (!ft_isdigit(argv[1]))
	{
		ft_printf("Error: invalid PID\n");
		return (1);
	}
	pid_server = ft_atoi(argv[1]);

	if (pid_server <= 0)
	{
		ft_printf("Error: invalid PID\n");
		return (1);
	}
	// signal(SIGUSR1, handle_ack);
	// signal(SIGUSR2, handle_ack);
	while (argv[2][i]) {
		send_signal(pid_server, argv[2][i]);
		i++;
	}
	send_signal(pid_server, '\0');
	return 0;
}