# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 17:13:38 by nkarpeko          #+#    #+#              #
#    Updated: 2023/04/21 16:10:21 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c ft_putchar.c ft_type_identifier.c \
		ft_type_distributor_middleware.c ft_putnum.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

# SRCS_bonus = ft_lstnew.c  ft_lstsize.c ft_lstiter.c \
# 			 ft_lstlast.c ft_lstmap.c ft_lstadd_front.c \
# 			 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
					
# OBJS_bonus :=$(SRCS_bonus:.c=.o)

# MYLIB = ./lib/Makefile

# include $(MYLIB)

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