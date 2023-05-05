#include "get_next_line.h"

int	main(void)
{
	int fd;
	fd = open("file.txt", O_RDONLY);
	// char str[] = "line I\nline II\nline III\nline IV\nline V";
	// ft_remove_first_line(str);
	// puts(str);
	// 	ft_remove_first_line(str);
	// puts(str);
	// 	ft_remove_first_line(str);
	// puts(str);
	// return (0);

	char *response = get_next_line(fd);
	printf("1__return: %s", response);
	response = get_next_line(fd);
	printf("2__return: %s", response);
	// response = get_next_line(fd);
	// printf("3__return: %s", response);
	// response = get_next_line(fd);
	// printf("4__return: %s", response);
	// response = get_next_line(fd);
	// printf("5__return: %s", response);
	// response = get_next_line(fd);
	// printf("6__return: %s", response);
	// response = get_next_line(fd);
	// printf("7__return: %s", response);
	// response = get_next_line(fd);
	// printf("8__return: %s", response);
	// response = get_next_line(fd);
	// printf("9__return: %s", response);
	// response = get_next_line(fd);
	// printf("10_return: %s", response);
	// response = get_next_line(fd);
	// printf("11_return: %s", response);
	// response = get_next_line(fd);
	// printf("12_return: %s", response);
	// response = get_next_line(fd);
	// printf("13_return: %s", response);
	// response = get_next_line(fd);
	// printf("14_return: %s", response);
	// response = get_next_line(fd);
	// printf("15_return: %s", response);
	// response = get_next_line(fd);
	// printf("16_return: %s", response);
	// response = get_next_line(fd);
	// printf("___return: %s", response);

	free(response);
	close(fd);
}