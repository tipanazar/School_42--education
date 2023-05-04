/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/04 16:06:44 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*return_str;
	static char	*str_saver;
	int			read_amount;
	// int			new_line_idx;

	if (fd < 0 || fd > FOPEN_MAX || !BUFFER_SIZE)
		return (NULL);
	return_str = NULL;
	if (!str_saver)
	{
		str_saver = NULL;
		read_amount = read(fd, buffer, BUFFER_SIZE);
		while (read_amount)
		{
			buffer[read_amount] = '\0';
			str_saver = ft_strcat(str_saver, buffer);
			buffer[0] = '\0';
			read_amount = read(fd, buffer, BUFFER_SIZE);
		}
	}
	if (!ft_strlength(str_saver))
		return (NULL);
	return_str = ft_strjoin_to_new_line(return_str, str_saver);
	// str_saver += ft_str_with_new_line_length(str_saver);
	// new_line_idx = ft_str_with_new_line_length(str_saver);
	// ft_memmove(str_saver, str_saver + new_line_idx, ft_strlength(str_saver)
	// 		- new_line_idx + 1);
	ft_remove_first_line(str_saver);
	// ft_strcpy(str_saver, str_saver, ft_str_with_new_line_length(str_saver));
	return (return_str);
}
