NAME = libft.a

SRCS =  ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strdup.c ft_substr.c \
		ft_strlcat.c ft_strncmp.c  ft_isalpha.c ft_strlen.c ft_strrchr.c \
		ft_memcpy.c ft_strchr.c ft_strlcpy.c ft_memmove.c ft_calloc.c \
		ft_tolower.c ft_bzero.c ft_isascii.c ft_memcpy.c ft_atoi.c \
		ft_strnstr.c ft_toupper.c ft_isdigit.c ft_memchr.c ft_memset.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_strtrim.c ft_strjoin.c ft_putendl_fd.c ft_putnbr_fd.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

SRCS_bonus = ft_lstnew.c  ft_lstsize.c ft_lstiter.c \
			 ft_lstlast.c ft_lstmap.c ft_lstadd_front.c \
			 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
					
OBJS_bonus :=$(SRCS_bonus:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(OBJS_bonus)
	ar -crs $(NAME) $(OBJS_bonus)

$(NAME) : $(OBJS)
	ar -crs $@ $^

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_bonus)
fclean: clean
	rm -f $(NAME)
re: fclean all