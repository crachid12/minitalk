/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:12:39 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 18:22:27 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_puthex_low(int fd, unsigned long nbr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_puthex_low(fd, nbr / 16);
	count += ft_putchar(fd, base[nbr % 16]);
	return (count);
}

int	ft_puthex_up(int fd, unsigned long nbr)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (nbr >= 16)
		count += ft_puthex_up(fd, nbr / 16);
	count += ft_putchar(fd, base[nbr % 16]);
	return (count);
}
