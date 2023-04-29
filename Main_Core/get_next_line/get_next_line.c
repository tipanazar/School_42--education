/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/29 19:13:25 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*return_str;
	static char	*str_saver;

	// printf("\nSAVER: %s\n",str_saver);
	return_str = (char *)malloc(1);
	return_str[0] = '\0';

	if (str_saver)
	{
		// printf("\nStr saver before: %s\nLength: %d\n\n", str_saver, ft_strlength(str_saver));
		return_str = ft_strjoin(return_str, str_saver);
		// free(str_saver);
		str_saver += ft_str_with_new_line_length(str_saver);
		// printf("\nStr saver after: %s\nLength: %d\n\n", str_saver, ft_strlength(str_saver));
	}

	// printf("\nReturn STRING: %s\n", return_str);
	while (ft_check_str_new_line(return_str) == -1 && read(fd, buffer,
			BUFFER_SIZE)){
		return_str = ft_strjoin(return_str, buffer);
	// printf("\nIs new line exist: %d\n",ft_check_str_new_line(return_str));
		}
	str_saver = ft_write_after_new_line(buffer);
	printf("\nNew SAVER: %s\n",str_saver);
	return (return_str);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	printf("F_return: %s", get_next_line(fd));
	printf("S_return: %s", get_next_line(fd));
	printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("T_return: %s", get_next_line(fd));
	// printf("F_return: %s", get_next_line(fd));
	close(fd);
}
