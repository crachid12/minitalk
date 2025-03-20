/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:47:26 by crachid-          #+#    #+#             */
/*   Updated: 2024/12/14 22:18:35 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(va_list ap, const char **format)
{
	if (**format == '%' && (*format)++)
		return (ft_putchar('%'));
	if (**format == 'c' && (*format)++)
		return (ft_putchar(va_arg(ap, int)));
	if (**format == 's' && (*format)++)
		return (ft_putstr(va_arg(ap, char *)));
	if ((**format == 'd' || **format == 'i') && (*format)++)
		return (ft_putnbr(va_arg(ap, int)));
	if (**format == 'u' && (*format)++)
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	if (**format == 'x' && (*format)++)
		return (ft_puthex_low(va_arg(ap, unsigned int)));
	if (**format == 'X' && (*format)++)
		return (ft_puthex_up(va_arg(ap, unsigned int)));
	if (**format == 'p' && (*format)++)
		return (ft_putpionter(va_arg(ap, void *)));
	return (0);
}

static int	check_format(va_list ap, const char *format, int counter)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += handle_format(ap, &format);
		}
		else
			counter += ft_putchar(*format++);
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, format);
	count = check_format(args, format, count);
	va_end(args);
	return (count);
}
