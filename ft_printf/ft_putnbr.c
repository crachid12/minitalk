/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:40:07 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 18:22:30 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_putnbr(int fd, int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr(fd, "-2147483648"));
	}
	if (n < 0)
	{
		count += ft_putchar(fd, '-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(fd, n / 10);
	c = (n % 10) + '0';
	count += ft_putchar(fd, c);
	return (count);
}

int	ft_putnbr_unsigned(int fd, unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(fd, n / 10);
	count += ft_putchar(fd, (n % 10) + '0');
	return (count);
}
