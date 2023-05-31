/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:37:56 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/31 14:39:20 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_game(void)
{
	int	i;

	i = -1;
	mlx_destroy_window(game()->mlx, game()->win);
	while (++i < (game()->map_lines))
		free(map()->map[i]);
	if (map()->map)
		free(map()->map);
	if (img()->chr_left)
		mlx_destroy_image(game()->mlx, img()->chr_left);
	if (img()->chr_right)
		mlx_destroy_image(game()->mlx, img()->chr_right);
	if (img()->floor)
		mlx_destroy_image(game()->mlx, img()->floor);
	if (img()->wall)
		mlx_destroy_image(game()->mlx, img()->wall);
	if (img()->colec)
		mlx_destroy_image(game()->mlx, img()->colec);
	if (img()->exit)
		mlx_destroy_image(game()->mlx, img()->exit);
	mlx_destroy_display(game()->mlx);
	free(game()->mlx);
	exit(0);
}

int	close_win(int keycode)
{
	(void)keycode;
	close_game();
	return (0);
}
