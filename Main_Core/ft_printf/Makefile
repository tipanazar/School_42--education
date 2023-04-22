# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 17:13:38 by nkarpeko          #+#    #+#              #
#    Updated: 2023/04/22 19:00:43 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS =  -Wall -Werror -Wextra 
RM = rm -f

NAME = libftprintf.a
COLOR_GREEN=\033[0;32m
COLOR_END = \033[0m
LIBFTDIR = ./lib
LIBFT = $(LIBFTDIR)/libft.a

SRCS = ft_printf.c ft_type_identifier.c \
	   ft_type_distributor_middleware.c 

OBJS = $(SRCS:.c=.o)

.PHONY:	all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cp $(LIBFT) $@
	ar -crs $@ $(OBJS) 
	echo "$(COLOR_GREEN)\nCOMPILING IS DONE!\n$(COLOR_END)"

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all
