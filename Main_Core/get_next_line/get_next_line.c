/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/28 20:49:04 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*return_str;
	char	*return_buffer;

	return_str = (char *)malloc(1); //!!

	while (ft_check_str_new_line(return_str) == -1 && read(fd, buffer, BUFFER_SIZE))
	{
		return_buffer = (char *)malloc(ft_str_with_new_line_length(buffer));
		// printf("\nNew line string length: %d\nNew line idx: %d\n",ft_str_with_new_line_length(buffer), ft_check_str_new_line(buffer));
		if (!return_buffer)
			return (NULL);
		// printf("\nBuffer length: %d\n", ft_str_with_new_line_length(buffer) );
		// printf("Buffer string: %s\n", buffer );
		ft_strcpy(buffer, return_buffer, ft_str_with_new_line_length(buffer) );
		// printf("Return buffer: %s\n", return_buffer);
		return_str = ft_strjoin(return_str, return_buffer);
		// printf("\nMain return string: %s\n", return_str);
		// free(return_buffer);                          //* ?
	}
	return (return_str);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	// char str1[8] = "1234\n567";
	// char str2[5] = "12345";
	// char str2[ft_str_with_new_line_length(str1)];
	// char str1[6] = "12345";
	// char str2[6] = "67890";
	// printf("%ld",ft_strlength(str1) + ft_strlength(str2));
	
	printf("F_return: %s", get_next_line(fd));
	printf("S_return: %s", get_next_line(fd));
	printf("T_return: %s", get_next_line(fd));
	printf("F_return: %s", get_next_line(fd));

	// printf("Return: %s\n", ft_strjoin(str1, str2));
	close(fd);
	// printf("Length: %d\n", ft_str_with_new_line_length(str1));
	// ft_strcpy(str1, str2, ft_str_with_new_line_length(str1));
	// printf("Length: %d\nSrc: %s\nDest: %s",
	// ft_str_with_new_line_length(str1), str1, str2);
}
