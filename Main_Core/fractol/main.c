/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/03 19:58:15 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

void	ft_close(int keycode, t_vars *vars)
{
	ft_printf("keycode: %d\n", keycode);
	if (keycode == 6513)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L << 0, ft_close, &vars);
	mlx_loop(vars.mlx);
}

// int	main(void)
// {
// 	int		f_idx;
// 	int		s_idx;
// 	int		blue;
// 	int		yellow;
// 	void	*mlx_window;
// 	void	*mlx_connection;

// 	f_idx = -1;
// 	s_idx = 0;
// 	blue = 0x0000ff;
// 	yellow = 0xffff00;
// 	mlx_connection = mlx_init();
// 	mlx_window = mlx_new_window(mlx_connection, 800, 600, "Glory to Ukraine!");
// 	while (++f_idx <= 700)
// 	{
// 		while (++s_idx <= 250)
// 		{
// 			mlx_pixel_put(mlx_connection, mlx_window, 50 + f_idx, 50 + s_idx,
// 					blue + s_idx);
// 			mlx_pixel_put(mlx_connection, mlx_window, 50 + f_idx, 300 + s_idx,
// 					yellow);
// 		}
// 		s_idx = 0;
// 	}
// 	mlx_loop(mlx_connection);
// }
