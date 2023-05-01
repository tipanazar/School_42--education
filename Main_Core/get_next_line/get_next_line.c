/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/01 17:04:23 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*return_str;
	static char	*str_saver;

	if (!str_saver)
	{
		str_saver = (char *)malloc(1);
		str_saver[0] = '\0';
		while (read(fd, buffer, BUFFER_SIZE))
		{
			buffer[BUFFER_SIZE] = '\0';
			// printf("\nBuffer: %s\n", buffer);
			str_saver = ft_strcat(str_saver, buffer);
		}
	}
	return_str = (char *)malloc(1);
	return_str[0] = '\0';
	if (str_saver)
	{
		// printf("\nStr saver before: %s\nLength: %d\n", str_saver,
		// 		ft_strlength(str_saver));
		return_str = ft_strjoin_to_new_line(return_str, str_saver);
		str_saver += ft_str_with_new_line_length(str_saver);
		// printf("\nStr saver after: %s\nLength: %d\n\n", str_saver,
		// 		ft_strlength(str_saver));
	}
	// printf("\nNew SAVER: %s\n",str_saver);
	return (return_str);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("file.txt", O_RDONLY);
// 	printf("1__return: %s", get_next_line(fd));
// 	// printf("2__return: %s", get_next_line(fd));
// 	// printf("3__return: %s", get_next_line(fd));
// 	// printf("4__return: %s", get_next_line(fd));
// 	// printf("5__return: %s", get_next_line(fd));
// 	// printf("6__return: %s", get_next_line(fd));
// 	// printf("7__return: %s", get_next_line(fd));
// 	// printf("8__return: %s", get_next_line(fd));
// 	// printf("9__return: %s", get_next_line(fd));
// 	// printf("10_return: %s", get_next_line(fd));
// 	// printf("11_return: %s", get_next_line(fd));
// 	// printf("12_return: %s", get_next_line(fd));
// 	// printf("13_return: %s", get_next_line(fd));
// 	// printf("14_return: %s", get_next_line(fd));
// 	// printf("15_return: %s", get_next_line(fd));
// 	// printf("16_return: %s", get_next_line(fd));
// 	// printf("___return: %s", get_next_line(fd));
// 	close(fd);
// }
