/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:14 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 18:37:49 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(t_vars *vars, 	t_game *game)
{
	(void)game;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_handle_key(int keycode, t_vars *vars, t_game *game)
{
	(void)vars;
	(void)game;
	ft_printf("Keyboard: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

// int	ft_mouse_handler(int button, int x, int y, t_vars *vars)
// {
// 	(void)x;
// 	(void)y;
// 	// printf("Button: %d\nX: %d\nY: %d\n\n", button, x, y);
// 	if (button == 4)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->img);
// 		ft_render(vars);
// 	}
// 	else if (button == 5)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->img);
// 		ft_render(vars);
// 	}
// 	else if (button == 1)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->img);
// 		ft_render(vars);
// 	}
// 	else if (button == 3)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->img);
// 		ft_render(vars);
// 	}
// 	return (0);
// }
