CC = cc

CFLAGS =  -Wall -Werror -Wextra 
RM = rm -f

NAME = minitalk.a
COLOR_GREEN=\033[0;32m
COLOR_END = \033[0m
LIBFTDIR = ./lib
LIBFT = $(LIBFTDIR)/libft.a

SRCS = server.c client.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) 
	cp $(LIBFT) $@
	ar -crs $@ $(OBJS) 
	echo "$(COLOR_GREEN)\nCOMPILING IS DONE!\n$(COLOR_END)"

$(LIBFT):
	make -C $(LIBFTDIR)

clean:
	$(RM) $(LIBFT)
	$(RM) $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re