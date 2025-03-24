# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crachid- <crachid-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 20:07:51 by crachid-          #+#    #+#              #
#    Updated: 2025/03/24 21:14:32 by crachid-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
SRC_CLIENT = client.c
SRC_SERVER = server.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
LIBFT = ./ft_printf/libftprintf.a

all: printf $(CLIENT) $(SERVER)

printf:
	make -C ./ft_printf

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(LIBFT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) clean -C ./ft_printf

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) fclean -C ./ft_printf

re: fclean all
