/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:22:04 by crachid-          #+#    #+#             */
/*   Updated: 2025/03/24 21:33:30 by crachid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_putchar(int fd, int c);
int	ft_puthex_low(int fd, unsigned long nbr);
int	ft_puthex_up(int fd, unsigned long nbr);
int	ft_putnbr(int fd, int n);
int	ft_putnbr_unsigned(int fd, unsigned int n);
int	ft_putstr(int fd, char *str);
int	ft_putpionter(int fd, void *p);
int	ft_atoi(const char *str);

#endif