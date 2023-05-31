/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:11:39 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/31 14:33:46 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	walk_right(void);
static void	walk_left(void);
static void	walk_up(void);
static void	walk_down(void);

int	keyhook(int keycode)
{
	if (keycode == 65307)
		close_game();
	else
	{
		if (keycode == 100 || keycode == 65363)
			walk_right();
		else if (keycode == 97 || keycode == 65361)
			walk_left();
		else if (keycode == 119 || keycode == 65362)
			walk_up();
		else if (keycode == 115 || keycode == 65364)
			walk_down();
	}
	fill_map();
	return (0);
}

static void	walk_right(void)
{
	(chr()->img) = img()->chr_right;
	if (map()->map[chr()->x][(chr()->y) + 1] == '1')
		return ;
	if (map()->map[chr()->x][(chr()->y) + 1] == 'c')
	{
		map()->map[chr()->x][(chr()->y) + 1] = 'o';
		map()->c -= 1;
	}
	ft_printf("Moves: %d\n", (++game()->moves));
	chr()->y += 1;
}

static void	walk_left(void)
{
	(chr()->img) = img()->chr_left;
	if (map()->map[chr()->x][(chr()->y) - 1] == '1')
		return ;
	if (map()->map[chr()->x][(chr()->y) - 1] == 'c')
	{
		map()->map[chr()->x][(chr()->y) - 1] = 'o';
		map()->c -= 1;
	}
	ft_printf("Moves: %d\n", (++game()->moves));
	chr()->y -= 1;
}

static void	walk_up(void)
{
	if (map()->map[(chr()->x) - 1][chr()->y] == '1')
		return ;
	if (map()->map[(chr()->x) - 1][chr()->y] == 'c')
	{
		map()->map[(chr()->x) - 1][chr()->y] = 'o';
		map()->c -= 1;
	}
	ft_printf("Moves: %d\n", (++game()->moves));
	chr()->x -= 1;
}

static void	walk_down(void)
{
	if (map()->map[(chr()->x) + 1][chr()->y] == '1')
		return ;
	if (map()->map[(chr()->x) + 1][chr()->y] == 'c')
	{
		map()->map[(chr()->x) + 1][chr()->y] = 'o';
		map()->c -= 1;
	}
	ft_printf("Moves: %d\n", (++game()->moves));
	chr()->x += 1;
}
