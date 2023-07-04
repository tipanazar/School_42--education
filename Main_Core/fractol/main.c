/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/04 19:45:54 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_define_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 600, "Glory to Ukraine!");
	vars->f_idx = -1;
	vars->s_idx = 0;
	vars->blue = 0x0000ff;
	vars->yellow = 0xffff00;
	vars->height = 250;
	vars->width = 700;
}

void	ft_render(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	while (++vars->f_idx <= vars->width)
	{
		while (++vars->s_idx <= vars->height)
		{
			my_mlx_pixel_put(vars, 50 + vars->f_idx, 50 + vars->s_idx,
					vars->blue);
			my_mlx_pixel_put(vars, 50 + vars->f_idx, 300 + vars->s_idx,
					vars->yellow);
		}
		vars->s_idx = 0;
	}
	vars->f_idx = -1;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

int	main(void)
{
	t_vars	vars;

	ft_define_vars(&vars);
	ft_render(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_handle, &vars);
	mlx_loop(vars.mlx);
}
