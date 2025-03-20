/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:14:24 by crachid-          #+#    #+#             */
/*   Updated: 2024/12/14 22:19:04 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpionter(void *p)
{
	int	count;

	count = 0;
	if (p == NULL)
	{
		count += ft_putstr("0x0");
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex_low((unsigned long)p);
	}
	return (count);
}
