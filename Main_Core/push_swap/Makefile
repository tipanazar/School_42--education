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

NAME = push_swap.a
COLOR_GREEN=\033[0;32m
COLOR_END = \033[0m
LIBFTDIR = ./lib
LIBFT = $(LIBFTDIR)/libft.a

SRCS = main.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cp $(LIBFT) $@
	ar -crs $@ $(OBJS) 
	$(CC) $(CFLAGS) $(SRCS) $(NAME) -o push_swap
	echo "$(COLOR_GREEN)\nCOMPILING IS DONE!\n$(COLOR_END)"

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) push_swap

re: fclean all

.PHONY: all clean fclean re
