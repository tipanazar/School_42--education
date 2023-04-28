/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/28 14:45:17 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*get_next_line(int fd)
// {
// 	static char	content[BUFFER_SIZE + 1];
// 	char		*safe;
// 	int			flag;

// 	flag = 0;
// 	safe = NULL;
// 	if (fd < 0 || fd > FOPEN_MAX || !BUFFER_SIZE)
// 		return (NULL);
// 	if (read(fd, 0, 0) < 0)
// 		return (ft_null_buff(content));
// 	while (content[0] || read(fd, content, BUFFER_SIZE) > 0)
// 	{
// 		safe = ft_content_safer(safe, content);
// 		ft_manage_buff(content, &flag);
// 		if (flag)
// 			break ;
// 	}
// 	return (safe);
// }

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*return_str;
	int		chars_amount;

	chars_amount = read(fd, buffer, BUFFER_SIZE);
	printf("String length: %d\nBuffer size: %d\n", ft_strlength(buffer),
			BUFFER_SIZE);
	printf("Chars amount: %d\nResult string: %s\n", chars_amount, buffer);
	return_str = (char *)malloc(ft_str_with_new_line_length(buffer));
	ft_strcpy(buffer, return_str, ft_str_with_new_line_length(buffer));
	return (return_str);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("Return: %s\n", get_next_line(fd));
	close(fd);

	// char str1[8] = "1234\n567";
	// char str2[5];
	// printf("Length: %d\n", ft_str_with_new_line_length(str1));
	// ft_strcpy(str1, str2, ft_str_with_new_line_length(str1));
	// printf("Src: %s\nDest: %s\n", str1, str2);
}
