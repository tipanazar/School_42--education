# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 18:50:44 by nkarpeko          #+#    #+#              #
#    Updated: 2023/05/20 15:50:18 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =  -Wall -Werror -Wextra
RM = rm -f

EXECUTABLE = push_swap
COLOR_GREEN=\033[0;32m
COLOR_END = \033[0m
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

SRCS = main.c test.c list-tester.c

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIBFT)
	cp $(LIBFT) $@
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(EXECUTABLE)
	echo "$(COLOR_GREEN)\nCOMPILING IS DONE!\n$(COLOR_END)"

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) $(LIBFT)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
