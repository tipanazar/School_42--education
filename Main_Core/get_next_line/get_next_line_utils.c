/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:00:19 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/01 16:45:29 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlength(char *str)
{
	int	length;

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
		if (str[length] == '\n')
			return (length + 1);
		length++;
		// return (length);
	}
	// printf("\nStr: %s\nLen: %d\n", str, length);
	return (length);
}

// void	ft_strcpy(char *src, char *dest, int len)
// {
// 	if (!src || !dest)
// 		return ;
// 	while (*src && len--) //! pre-decrement issue?
// 		*dest++ = *src++;
// }

// int	ft_check_str_new_line(char *str)
// {
// 	int	idx;

// 	idx = -1;
// 	while (str[++idx])
// 		if (str[idx] == '\n')
// 			return (idx);
// 	return (-1);
// }

char	*ft_strjoin_to_new_line(char *s1, char *s2)
{
	char	*result_str;
	int		idx;
	int		to_new_line_len;

	to_new_line_len = ft_str_with_new_line_length(s2) + 1;
	// printf("\nStr: %s\nLen: %d\n", s2, to_new_line_len);
	idx = -1;
	result_str = (char *)malloc(ft_strlength(s1) + to_new_line_len);
	//! could be an error
	while (*s1)
		result_str[++idx] = *s1++;
	while (--to_new_line_len)
		result_str[++idx] = *s2++;
	// result_str[++idx] = '\0';
	return (result_str);
}

char	*ft_strcat(char *s1, char *s2)
{
	char	*result_str;
	int		idx;

	idx = -1;
	result_str = (char *)malloc(ft_strlength(s1) + ft_strlength(s2));
	//! could be an error
	while (*s1)
		result_str[++idx] = *s1++;
	while (*s2)
		result_str[++idx] = *s2++;
	// result_str[++idx] = '\0';
	return (result_str);
}

// char	*ft_strcat(char *s1, char *s2)
// {
// 	char	*result_str;
// 	int		idx;
// 	int		s_idx;

// 	s_idx = 0;
// 	idx = 0;
// 	result_str = (char *)malloc(ft_strlength(s1) + ft_strlength(s2));
// 	//! could be an error
// 	while (s1[s_idx])
// 		result_str[idx++] = s1[s_idx++];
// 	s_idx = 0;
// 	while (s2[s_idx])
// 		result_str[idx++] = s2[s_idx++];
// 	// result_str[++idx] = '\0';
// 	return (result_str);
// }

char	*ft_write_after_new_line(char *str)
{
	int f_idx = 0;
	int s_idx = 0;
	char *return_str;
	if (ft_str_with_new_line_length(str) != ft_strlength(str))
		f_idx = ft_str_with_new_line_length(str); //!
	return_str = (char *)malloc(ft_strlength(str) - f_idx);
	if (!return_str)
		return (NULL);
	while (str[f_idx])
		return_str[s_idx++] = str[f_idx++];

	return (return_str);
}