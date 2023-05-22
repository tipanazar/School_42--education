# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 13:46:04 by nkarpeko          #+#    #+#              #
#    Updated: 2023/05/19 20:12:46 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = \033[0;32m
COLOR_END = \033[0m
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SERVER = server
CLIENT = client
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS = server.c client.c

all: $(LIBFT)

$(LIBFT):
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)
	echo "$(COLOR_GREEN)\nCOMPILING IS DONE!\n$(COLOR_END)"

clean:
	$(RM) $(LIBFT)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(SERVER)
	$(RM) $(CLIENT)

re: clean all

.PHONY:	all clean fclean re