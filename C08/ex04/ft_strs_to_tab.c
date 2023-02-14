/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:25:35 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/14 19:37:22 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_str_length(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strcopy(char *str)
{
	int		idx;
	char	*string;

	idx = 0;
	string = (char *)malloc(ft_str_length(str) + 1);
	if (!string)
		return (NULL);
	while (str[idx])
	{
		string[idx] = str[idx];
		idx++;
	}
	string[idx] = '\0';
	return (string);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					idx;
	struct s_stock_str	*arr;

	arr = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!arr)
		return (NULL);
	idx = 0;
	while (idx < ac)
	{
		arr[idx].size = ft_str_length(av[idx]);
		arr[idx].str = av[idx];
		arr[idx].copy = ft_strcopy(av[idx]);
		idx++;
	}
	arr[idx] = (struct s_stock_str){0, 0, 0};
	return (arr);
}

// #include "ft_stock_str.h"
// #include <stdio.h>
// struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
// int	main(void)
// {
// 	char	*strings[] = {"string1", "string2", "stringmuitomaior1", "fim", "",
// 			"loucura", "issae"};
// 	struct s_stock_str *tab = ft_strs_to_tab(7, strings);
// 	struct s_stock_str *it = tab;

// 	tab[1].copy[3] = 'o';
// 	tab[3].copy[0] = 'S';

// 	while (it->str != 0)
// 	{
// 		printf("%s\n", it->str);
// 		printf("%i\n", it->size);
// 		printf("%s\n", it->copy);
// 		printf("\n");
// 		++it;
// 	}
// }