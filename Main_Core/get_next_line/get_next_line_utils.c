/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:00:19 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/02 17:06:37 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlength(char *str)
{
	int	length;

	length = 0;
	if (!str)
		return (0);
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
		if (str[length] == '\n')
			return (length + 1);
		length++;
	}
	return (length);
}

char	*ft_strjoin_to_new_line(char *s1, char *s2)
{
	char	*result_str;
	int		idx;
	int		to_new_line_len;

	to_new_line_len = ft_str_with_new_line_length(s2) + 1;
	idx = -1;
	result_str = (char *)malloc(ft_strlength(s1) + to_new_line_len);
	if (!result_str)
		return (NULL);
	if (s1)
		while (*s1)
			result_str[++idx] = *s1++;
	while (--to_new_line_len)
		result_str[++idx] = *s2++;
	result_str[++idx] = '\0';
	return (result_str);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*result_str;
	int		idx;

	idx = -1;
	result_str = (char *)malloc(ft_strlength(s1) + ft_strlength(s2) + 1);
	if (!result_str)
		return (NULL);
	if (s1)
		while (*s1)
			result_str[++idx] = *s1++;
	while (*s2)
		result_str[++idx] = *s2++;
	result_str[++idx] = '\0';
	return (result_str);
}

void	ft_str_cleaner(char *str, int start)
{
	while (str[start])
		str[start++] = '\0';
}
