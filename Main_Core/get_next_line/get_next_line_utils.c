/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:00:19 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/04 21:27:41 by nkarpeko         ###   ########.fr       */
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

int	ft_new_line_detector(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		if (str[idx++] == '\n')
			return (idx);
	return (0);
}

char	*ft_strjoin_to_new_line(char *s1, char *s2)
{
	char	*result_str;
	int		f_idx;
	int		to_new_line_len;

	f_idx = 0;
	to_new_line_len = ft_str_with_new_line_length(s2) + 1;
	result_str = (char *)malloc(ft_strlength(s1) + to_new_line_len );
	// printf("Alloc amount: %d\n", ft_strlength(s1) + to_new_line_len );
	if (!result_str)
		return (NULL);
	if (s1)
	{
		while (s1[f_idx])
		{
			result_str[f_idx] = s1[f_idx];
			f_idx++;
		}
		free(s1);
	}
	while (--to_new_line_len)
		result_str[f_idx++] = *s2++;
	result_str[f_idx] = '\0';
	// printf("\nResult: %s\n", result_str);
	return (result_str);
}

void	ft_remove_first_line(char *str)
{
	int	second_line_idx;
	int	new_str_len;
	int	idx;

	second_line_idx = ft_str_with_new_line_length(str);
	new_str_len = ft_strlength(str) - second_line_idx;
	idx = 0;
	while (new_str_len--)
		str[idx++] = str[second_line_idx++];
	str[idx] = '\0';
	while (str[++idx])
		str[idx] = '\0';
}

void	ft_str_cleaner(char *str, int start)
{
	while (str[start])
		str[start++] = '\0';
}