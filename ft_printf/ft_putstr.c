/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:20:10 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 18:22:36 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(fd, "(null)", 6));
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}
