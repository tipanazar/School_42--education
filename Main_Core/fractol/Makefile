# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/01 17:04:44 by nkarpeko          #+#    #+#              #
#    Updated: 2023/07/02 18:18:36 by tipanazar        ###   ########.fr        #
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
MINILIBXDIR = ./mlx_linux
MINILIBX = $(MINILIBXDIR)/libmlx_Linux.a
MINILIBXCOMPILE = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRCS = *.c 
	
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)
	@cp $(MINILIBX) $@
	@cp $(LIBFT) $@
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MINILIBXCOMPILE) -o $(NAME)
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
