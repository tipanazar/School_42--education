# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 17:13:38 by nkarpeko          #+#    #+#              #
#    Updated: 2023/04/20 17:16:30 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_isalnum.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

# SRCS_bonus = ft_lstnew.c  ft_lstsize.c ft_lstiter.c \
# 			 ft_lstlast.c ft_lstmap.c ft_lstadd_front.c \
# 			 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
					
OBJS_bonus :=$(SRCS_bonus:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

# bonus: $(OBJS_bonus)
# 	ar -crs $(NAME) $(OBJS_bonus)

$(NAME) : $(OBJS)
	ar -crs $@ $^

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_bonus)
fclean: clean
	rm -f $(NAME)
re: fclean all 	