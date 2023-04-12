/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:27:09 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/14 19:39:02 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
	}
}

// #include "ft_stock_str.h"
// #include <stdlib.h>

// int	ft_str_length(char *str)
// {
// 	int	idx;

// 	idx = 0;
// 	while (str[idx])
// 		idx++;
// 	return (idx);
// }

// char	*ft_strcopy(char *str)
// {
// 	int		idx;
// 	char	*string;

// 	idx = 0;
// 	string = (char *)malloc(ft_str_length(str) + 1);
// 	if (!string)
// 		return (NULL);
// 	while (str[idx])
// 	{
// 		string[idx] = str[idx];
// 		idx++;
// 	}
// 	string[idx] = '\0';
// 	return (string);
// }

// struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
// {
// 	int					idx;
// 	struct s_stock_str	*arr;

// 	arr = malloc((ac + 1) * sizeof(struct s_stock_str));
// 	if (!arr)
// 		return (NULL);
// 	idx = 0;
// 	while (idx < ac)
// 	{
// 		arr[idx].size = ft_str_length(av[idx]);
// 		arr[idx].str = av[idx];
// 		arr[idx].copy = ft_strcopy(av[idx]);
// 		idx++;
// 	}
// 	arr[idx] = (struct s_stock_str){0, 0, 0};
// 	return (arr);
// }
// int		main(void)
// {
// 	char	*strings[] = {"string1", "string2", "stringmuitomaior1", "fim", "",
//			"loucura", "issae"};
// 	struct s_stock_str *tab = ft_strs_to_tab(7, strings);

// 	ft_show_tab(tab);
// }