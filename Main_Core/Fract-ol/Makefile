# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 17:04:44 by nkarpeko          #+#    #+#              #
#    Updated: 2023/07/01 20:45:53 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =  -Wall -Werror -Wextra
RM = rm -f

NAME = fractol
COLOR_GREEN=\033[0;32m
COLOR_END = \033[0m
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
MINILIBXDIR = ./minilibx-linux
MINILIBX = $(MINILIBXDIR)/libmlx.a
SRCS = main.c 
	
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)
	@cp $(LIBFT) $@
	@cp $(MINILIBX) $@
# @$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@make -s clean
	@echo "$(COLOR_GREEN)\n✅---COMPILING IS DONE---✅\n$(COLOR_END)"

$(LIBFT):
	@make -sC $(LIBFTDIR)
	
$(MINILIBX):
	@make -sC $(MINILIBXDIR)	

clean:
	@$(RM) $(LIBFT)
	@make -sC $(LIBFTDIR) clean
	@make -sC $(MINILIBXDIR) clean

fclean: clean
	@$(RM) $(NAME)

re: fclean all
