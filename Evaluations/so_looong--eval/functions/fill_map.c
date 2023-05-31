/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 01:08:57 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/30 16:19:00 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	put_floor(int x, int y);
static void	put_wall(int x, int y);
static void	put_colec(int x, int y);
static void	put_exit(int x, int y);

void	fill_map(void)
{
	int		y;
	int		x;

	if (map()->c == 0 && map()->map[chr()->x][chr()->y] == 'e')
		close_game();
	y = -1;
	while (++y < (game()->map_lines))
	{
		x = -1;
		while (map()->map[y][++x])
		{
			if (x == chr()->y && y == chr()->x)
				continue ;
			else if (map()->map[y][x] == '0' || map()->map[y][x] == 'o')
				put_floor(x, y);
			else if (map()->map[y][x] == '1')
				put_wall(x, y);
			else if (map()->map[y][x] == 'c')
				put_colec(x, y);
			else if (map()->map[y][x] == 'e')
				put_exit(x, y);
		}
	}
	mlx_put_image_to_window(game()->mlx, game()->win,
		chr()->img, chr()->y * 60, chr()->x * 60);
}

static void	put_floor(int x, int y)
{
	mlx_put_image_to_window(game()->mlx, game()->win,
		img()->floor, x * 60, y * 60);
}

static void	put_wall(int x, int y)
{
	mlx_put_image_to_window(game()->mlx, game()->win,
		img()->wall, x * 60, y * 60);
}

static void	put_colec(int x, int y)
{
	mlx_put_image_to_window(game()->mlx, game()->win,
		img()->colec, x * 60, y * 60);
}

static void	put_exit(int x, int y)
{
	mlx_put_image_to_window(game()->mlx, game()->win,
		img()->exit, x * 60, y * 60);
}
