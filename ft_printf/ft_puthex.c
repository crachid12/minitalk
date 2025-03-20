/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:12:39 by crachid-          #+#    #+#             */
/*   Updated: 2024/12/14 22:18:50 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low(unsigned long nbr)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_puthex_low(nbr / 16);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_puthex_up(unsigned long nbr)
{
	char	*base;
	int		count;

	base = "0123456789ABCDEF";
	count = 0;
	if (nbr >= 16)
		count += ft_puthex_up(nbr / 16);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}
