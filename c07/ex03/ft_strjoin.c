/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:03:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/14 14:34:10 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*my_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	return (dest);
}

int	calc_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;
	int	sep_len;

	len = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			len++;
	}
	sep_len = 0;
	while (*(sep++))
		sep_len++;
	return (len + (size - 1) * sep_len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*root;
	int		len;
	int		i;
	char	*tmp;

	if (size == 0)
	{
		res = malloc(1);
		*res = 0;
		return (res);
	}
	len = calc_len(size, strs, sep);
	res = malloc(len);
	root = res;
	res[len - 1] = 0;
	i = -1;
	while (++i < size)
	{
		tmp = res;
		res = my_strcpy(res, strs[i]);
		if (i != size - 1)
			res = my_strcpy(res, sep);
	}
	return (root);
}

// #include <stdio.h>
// #include <stdlib.h>
// int		main(void)
// {
// 	int		offset;
// 	char	**strs;
// 	char	*res_str;

// 	strs = malloc(3 * sizeof(char *));
// 	if (strs == NULL)
// 		return (1);
// 	offset = 0;
// 	while (offset < 3)
// 	{
// 		strs[offset] = "abc";
// 		offset++;
// 	}
// 	res_str = ft_strjoin(3, strs, ", ");
// 	if (res_str == NULL)
// 		return (1);
// 	printf("res: %s\n", res_str);
// 	free(strs);
// 	free(res_str);
// 	return (0);
// }