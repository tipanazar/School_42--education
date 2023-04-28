/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:00:19 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/28 19:35:21 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlength(char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

int	ft_str_with_new_line_length(char *str)
{
	int	length;

	length = 0;
	while (str[length])
	{
		length++;
		if (str[length] == '\n')
			return (++length);
	}
	return (length);
}

void	ft_strcpy(char *src, char *dest, int len)
{
	if (!src || !dest)
		return ;
	while (*src  &&  len--) //! pre-decrement issue?
		*dest++ = *src++;
}

int	ft_check_str_new_line(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		if (str[idx] == '\n')
			return (idx);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result_str;
	int		idx;

	idx = -1;
	result_str = (char *)malloc(ft_strlength(s1) + ft_strlength(s2));
		//! probably should add +1 byte
	//! could be an error
	while (*s1)
		result_str[++idx] = *s1++;
	while (*s2)
		result_str[++idx] = *s2++;
	// result_str[++idx] = '\0';
	return (result_str);
}
