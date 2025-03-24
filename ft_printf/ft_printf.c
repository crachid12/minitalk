/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:47:26 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 19:35:02 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

static int	handle_format(int fd, va_list ap, const char **format)
{
	if (**format == '%' && (*format)++)
		return (ft_putchar(fd, '%'));
	if (**format == 'c' && (*format)++)
		return (ft_putchar(fd, va_arg(ap, int)));
	if (**format == 's' && (*format)++)
		return (ft_putstr(fd, va_arg(ap, char *)));
	if ((**format == 'd' || **format == 'i') && (*format)++)
		return (ft_putnbr(fd, va_arg(ap, int)));
	if (**format == 'u' && (*format)++)
		return (ft_putnbr_unsigned(fd, va_arg(ap, unsigned int)));
	if (**format == 'x' && (*format)++)
		return (ft_puthex_low(fd, va_arg(ap, unsigned int)));
	if (**format == 'X' && (*format)++)
		return (ft_puthex_up(fd, va_arg(ap, unsigned int)));
	if (**format == 'p' && (*format)++)
		return (ft_putpionter(fd, va_arg(ap, void *)));
	return (0);
}

static int	check_format(int fd, va_list ap, const char *format, int counter)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += handle_format(fd, ap, &format);
		}
		else
			counter += ft_putchar(fd, *format++);
	}
	return (counter);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	if (write(fd, "", 0) == -1)
		return (-1);
	va_start(args, format);
	count = check_format(fd, args, format, count);
	va_end(args);
	return (count);
}
