NAME	=	so_long

FLAGS	=	-Wall -Werror -Wextra

CC		=	cc

LIB		=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11

INC		=	includes/so_long.h	\
			includes/libft.h	\

SRC		=	main/so_long.c	\
			functions/create_img.c	\
			functions/create_game.c	\
			functions/create_map.c	\
			functions/create_win.c	\
			functions/check_map.c	\
			functions/fill_map.c	\
			functions/events.c	\
			functions/close_game.c	\

all:	$(NAME)

$(NAME):
		make -C libft
		make -C mlx
		$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
		make clean -C libft
		make clean -C mlx

fclean:
		make fclean -C libft
		make clean -C mlx
		rm -f $(NAME)

re:		fclean
		make

.PHONY:	all clean fclean re