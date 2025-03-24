/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:14:24 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 18:22:33 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putpionter(int fd, void *p)
{
	int	count;

	count = 0;
	if (p == NULL)
	{
		count += ft_putstr(fd, "0x0");
	}
	else
	{
		count += ft_putstr(fd, "0x");
		count += ft_puthex_low(fd, (unsigned long)p);
	}
	return (count);
}
