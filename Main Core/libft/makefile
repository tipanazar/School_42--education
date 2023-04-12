# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 13:21:51 by nkarpeko          #+#    #+#              #
#    Updated: 2023/04/11 13:22:58 by nkarpeko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# SRCS =  ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strdup.c ft_putstr_fd.c\
# 		ft_strlcat.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_putnbr_fd.c\
# 		ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_substr.c ft_memmove.c\
# 		ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c ft_putendl_fd.c\
# 		ft_strlen.c ft_strrchr.c ft_calloc.c ft_putchar_fd.c ft_strnstr.c\
# 		ft_toupper.c ft_isdigit.c ft_memchr.c ft_memset.c ft_split.c ft_itoa.c\
# 		ft_strjoin.c  ft_strtrim.c ft_strmapi.c ft_striteri.c\
		

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	ar -crs $@ $^

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus