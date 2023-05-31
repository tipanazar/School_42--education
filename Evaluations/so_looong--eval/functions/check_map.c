/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:10:30 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/30 16:13:57 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(void)
{
	int		i;
	size_t	len;

	if (!map()->map[0])
		return (0);
	len = ft_strlen(map()->map[0]);
	if (!top_bot_check(map()->map[0], len))
		return (0);
	i = 1;
	while (i < (game()->map_lines) - 1)
	{
		if (!mid_check(map()->map[i], i)
			|| ft_strlen(map()->map[i]) != len)
			return (0);
		i++;
	}
	if (!top_bot_check(map()->map[i], len -1))
		return (0);
	if (map()->c == 0 || map()->e != 1 || map()->p != 1)
		return (0);
	path_check(chr()->y, chr()->x);
	if (map()->c != map()->_c || map()->e != map()->_e)
		return (0);
	return (1);
}

int	top_bot_check(char *line, size_t len)
{
	int	i;

	if (ft_strlen(line) != len)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	mid_check(char *line, int x)
{
	int	i;

	i = 1;
	if (line[0] != '1')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			return (0);
		obj_check(line[i], i, x);
		i++;
	}
	if (line[i - 1] != '1')
		return (0);
	return (1);
}

void	obj_check(char c, int y, int x)
{
	if (c == 'P')
	{
		chr()->y = y;
		chr()->x = x;
		map()->p += 1;
	}
	else if (c == 'C')
		map()->c += 1;
	else if (c == 'E')
		map()->e += 1;
}

void	path_check(int y, int x)
{
	if (!map()->map[x] || !map()->map[x][y] || map()->map[x][y] == '1'
		|| map()->map[x][y] == 'o' || map()->map[x][y] == 'c'
		|| map()->map[x][y] == 'e' || map()->map[x][y] == 'p')
		return ;
	if (map()->map[x][y] == '0')
		map()->map[x][y] = 'o';
	else if (map()->map[x][y] == 'P')
	{
		map()->map[x][y] = 'o';
	}
	else if (map()->map[x][y] == 'C')
	{
		map()->map[x][y] = 'c';
		map()->_c += 1;
	}
	else if (map()->map[x][y] == 'E')
	{
		map()->map[x][y] = 'e';
		map()->_e += 1;
	}
	path_check(y, x + 1);
	path_check(y + 1, x);
	path_check(y, x - 1);
	path_check(y - 1, x);
}
