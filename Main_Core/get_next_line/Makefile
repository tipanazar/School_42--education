# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 19:09:29 by nkarpeko          #+#    #+#              #
#    Updated: 2023/04/23 19:14:19 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS =  -Wall -Werror -Wextra 
RM = rm -f
COLOR_GREEN=\033[0;32m
COLOR_END = \033[0m

NAME = nextlinelib.a

SRCS = get_next_line.c

OBJS = $(SRCS:.c=.o)

.PHONY:	all clean fclean re

all: $(NAME)


$(NAME) : $(OBJS)
	ar -crs $@ $^
	echo "$(COLOR_GREEN)\nCOMPILING IS DONE!\n$(COLOR_END)"

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
