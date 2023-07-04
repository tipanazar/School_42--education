/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:14 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/04 19:43:21 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	ft_handle_key(int keycode, t_vars *vars)
{
	(void)vars;
	ft_printf("Keyboard: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	ft_mouse_handle(int button, int x, int y, t_vars *vars)
{
    (void)x;
    (void)y;
	// printf("Button: %d\nX: %d\nY: %d\n\n", button, x, y);
	if (button == 1)
	{
		vars->height /= 2;
		vars->width /= 2;
		mlx_destroy_image(vars->mlx, vars->img);
		ft_render(vars);
	}
    else if (button == 3)
    {
        vars->height *= 2;
        vars->width *= 2;
        mlx_destroy_image(vars->mlx, vars->img);
        ft_render(vars);
    }
	else if (button == 4)
	{
		vars->blue += 10;
		vars->yellow += 10;
		mlx_destroy_image(vars->mlx, vars->img);
		ft_render(vars);
	}
	else if (button == 5)
	{
		vars->blue -= 10;
		vars->yellow -= 10;
		mlx_destroy_image(vars->mlx, vars->img);
		ft_render(vars);
	}
	return (0);
}
