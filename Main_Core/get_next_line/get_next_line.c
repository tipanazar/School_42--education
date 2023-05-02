/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/02 17:00:23 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*return_str;
	static char	*str_saver;
	int			read_amount;

	return_str = NULL;
	if (!str_saver)
	{
		str_saver = NULL;
		read_amount = read(fd, buffer, BUFFER_SIZE);
		while (read_amount)
		{
			ft_str_cleaner(buffer, read_amount);
			str_saver = ft_strcat(str_saver, buffer);
			ft_str_cleaner(buffer, 0); //^ ???
			read_amount = read(fd, buffer, BUFFER_SIZE);
		}
	}
	if (!ft_strlength(str_saver))
		return (NULL);
	return_str = ft_strjoin_to_new_line(return_str, str_saver);
	str_saver += ft_str_with_new_line_length(str_saver);
	return (return_str);
}

int	main(void)
{
	int fd;

	fd = open("file.txt", O_RDONLY);
	// get_next_line(fd);
	// char *response = get_next_line(fd);
	// printf("Return: %s", response);
	printf("1__return: %s", get_next_line(fd));
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
	close(fd);
}