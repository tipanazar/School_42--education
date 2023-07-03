# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lupereir <lupereir@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:04:30 by lupereir          #+#    #+#              #
#    Updated: 2023/05/22 19:18:57 by lupereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	convert

SRCS		=	ScalarConverter.cpp \
				main.cpp

OBJS		=	${SRCS:.cpp=.o}

CC			=	c++
CPPFLAGS	=	-g -std=c++98 -Wall -Werror -Wextra -pedantic -fsanitize=address
RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

run: re
	clear && ./${NAME} a
	make fclean

.PHONY:		fclean, all, re, run
