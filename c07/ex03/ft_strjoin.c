/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:03:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/11 23:21:47 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	strs_lenght(int size, char **strs, char *sep)
{
	int	idx;
	int	total_length;
	int	strs_idx;
	int	sep_lenght;

	sep_lenght = 0;
	idx = 0;
	total_length = 0;
	strs_idx = 0;
	while (strs_idx < size)
	{
		while (strs[strs_idx][idx])
		{
			total_length++;
			idx++;
		}
		idx = 0;
		strs_idx++;
	}
	while (sep[sep_lenght])
		sep_lenght++;
	return (total_length + sep_lenght * (size - 1));
}

char	*tmp_string(char *str)
{
	int		idx;
	char	*temp;

	idx = 0;
	if (!str[0])
		return (0);
	temp = (char *)malloc(sizeof(str));
	if (!temp)
		return (0);
	while (str[idx])
	{
		temp[idx] = str[idx];
		idx++;
	}
	return (temp);
}

int	add_sep(char *string, int total_length, char *sep)
{
	int	idx;

	idx = 0;
	while (sep[idx])
	{
		string[total_length] = sep[idx];
		idx++;
		total_length++;
	}
	return (total_length);
}

void	final_string(char *string, int size, char **strs, char *sep)
{
	int		idx;
	int		total_length;
	int		str_idx;
	char	*temp;
	int		temp_size;

	str_idx = 0;
	idx = 0;
	total_length = 0;
	while (str_idx < size)
	{
		temp = tmp_string(strs[str_idx]);
		temp_size = sizeof(temp) / 4;
		while (idx <= temp_size)
		{
			string[total_length] = temp[idx];
			idx++;
			total_length++;
		}
		if (str_idx != size - 1)
			total_length = add_sep(string, total_length, sep);
		str_idx++;
		idx = 0;
	}
	string[total_length] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		str_idx;
	char	*string;

	if (size <= 0)
		return ((char *)malloc(sizeof(char)));
	str_idx = 0;
	total_length = strs_lenght(size, strs, sep);
	string = (char *)malloc(total_length);
	if (!string)
		return (0);
	final_string(string, size, strs, sep);
	return (string);
}

#include <stdio.h>
#include <stdlib.h>
char	*ft_strjoin(int size, char **strs, char *sep);

int		main(void)
{
	int		offset;
	char	**strs;
	char	*res_str;

	strs = malloc(3 * sizeof(char *));
	if (strs == NULL)
		return (1);
	offset = 0;
	while (offset < 3)
	{
		strs[offset] = "abc";
		offset++;
	}
	res_str = ft_strjoin(3, strs, ", ");
	if (res_str == NULL)
		return (1);
	printf("res: %s\n", res_str);
	free(strs);
	free(res_str);
	return (0);
}