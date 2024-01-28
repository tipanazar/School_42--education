CC = gcc -fsanitize=thread
# CC = gcc
CFLAGS =  -Wall -Werror -Wextra
RM = rm -f

NAME = philo
COLOR_GREEN=\033[0;32m
COLOR_END = \033[0m
SRCS = *.c 
	
all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(COLOR_GREEN)\n✅---COMPILING IS DONE---✅\n$(COLOR_END)"

clean:
	@$(RM) $(NAME)

fclean:
	@$(RM) $(NAME)

re: fclean all