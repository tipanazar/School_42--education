/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/04 21:25:11 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*return_str;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		ft_str_cleaner(buffer, 0);
		return (NULL);
	}
	return_str = NULL;
	if (ft_strlength(buffer))
	{
		// printf("\nExist: %s", buffer);
		return_str = ft_strjoin_to_new_line(return_str, buffer);
		ft_remove_first_line(buffer);
	}
	while (!ft_new_line_detector(buffer) && read(fd, buffer, BUFFER_SIZE))
	{
		// printf("\nBuffer: %s", buffer);
		// printf("\nLoop\n");
		return_str = ft_strjoin_to_new_line(return_str, buffer);
		if (!ft_new_line_detector(buffer))
			ft_str_cleaner(buffer, 0);
	}

	ft_remove_first_line(buffer);
	// printf("\nResult: %s\n", return_str);
	return (return_str);
}
