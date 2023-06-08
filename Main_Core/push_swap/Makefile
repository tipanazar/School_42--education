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

SRCS = main.c \
	utils/linked_list_operations.c \
	utils/stack_operations.c \
	utils/stack_combined_operations.c \
	checkers/checkers.c \
	algorithm/algorithm.c \
	algorithm/helpers.c 

all: $(EXECUTABLE)

$(EXECUTABLE): $(LIBFT)
	@cp $(LIBFT) $@
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(EXECUTABLE)
	@make -s clean
	@echo "$(COLOR_GREEN)\n✅---COMPILING IS DONE---✅\n$(COLOR_END)"

$(LIBFT):
	@make -sC $(LIBFTDIR)

clean:
	@$(RM) $(LIBFT)
	@make -sC $(LIBFTDIR) clean

fclean: clean
	@$(RM) $(EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
