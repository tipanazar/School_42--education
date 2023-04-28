/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/28 14:01:18 by nkarpeko         ###   ########.fr       */
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
	char	buffer[BUFFER_SIZE + 1];
    // char *return_str;
	int		chars_amount;

	chars_amount = read(fd, buffer, BUFFER_SIZE);
	printf("Amount: %d\n %s\n", chars_amount, buffer);
    printf("Length: %d", ft_strlength(buffer));
	return ("buffer");
}

int	main(void)
{
	int fd = open("file.txt", O_RDONLY);
	get_next_line(fd);
	close(fd);
}
