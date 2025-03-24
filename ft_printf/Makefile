# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 18:22:48 by crachid-          #+#    #+#              #
#    Updated: 2025/03/24 19:35:33 by crachid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libftprintf.a
CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
AR		:=	ar rcs
RM		:=	rm -f

SRCS	:=	ft_printf.c ft_putchar.c ft_putnbr.c ft_atoi.c ft_putstr.c ft_puthex.c ft_putpointer.c

OBJS	:=	$(SRCS:%c=%o)

all		:	 $(NAME)

%o		:	%c ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all