#include "get_next_line.h"

int	main(void)
{
	char str[] = "line I\nline II\nline III\nline IV\nline V";
		ft_memmove(str, str[ft_str_with_new_line_length(str)], ft_strlength(str) - ft_str_with_new_line_length(str));
	puts(str);
	return (0);
	// int fd;

	// fd = open("file.txt", O_RDONLY);
	// // get_next_line(fd);
	// char *response = get_next_line(fd);
	// printf("Return: %s", response);
	// free(response);
	// printf("1__return: %s", get_next_line(fd));
	// printf("2__return: %s", get_next_line(fd));
	// printf("3__return: %s", get_next_line(fd));
	// printf("4__return: %s", get_next_line(fd));
	// printf("5__return: %s", get_next_line(fd));
	// printf("6__return: %s", get_next_line(fd));
	// printf("7__return: %s", get_next_line(fd));
	// printf("8__return: %s", get_next_line(fd));
	// printf("9__return: %s", get_next_line(fd));
	// printf("10_return: %s", get_next_line(fd));
	// printf("11_return: %s", get_next_line(fd));
	// printf("12_return: %s", get_next_line(fd));
	// printf("13_return: %s", get_next_line(fd));
	// printf("14_return: %s", get_next_line(fd));
	// printf("15_return: %s", get_next_line(fd));
	// printf("16_return: %s", get_next_line(fd));
	// printf("\n___return: %s", get_next_line(fd));
	// close(fd);
}