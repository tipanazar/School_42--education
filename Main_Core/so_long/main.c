/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 13:20:48 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_define_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Window");
}

void	ft_loop(t_vars *vars)
{
	int	pos;
	int zero = 0;
	int	iter;

	iter = -1;
	pos = 0;
	char *path_arr[] = {"./files/textures/w221.xpm",
						"./files/textures/autobanh.xpm",
						"./files/textures/canister.xpm",
						"./files/textures/grass.xpm"};
	while (++iter < 4)
	{
		vars->img = mlx_xpm_file_to_image(vars->mlx, path_arr[iter], &zero,
				&zero);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, pos, 0);
		pos += 64;
	}
}

void	ft_render(t_vars *vars)
{
	ft_loop(vars);
}

int	main(void)
{
	t_vars	vars;

	ft_define_vars(&vars);
	ft_render(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_handler, &vars);
	mlx_loop(vars.mlx);
}
