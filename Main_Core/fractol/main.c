/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/02 19:39:49 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	int f_idx = -1;
	int s_idx = 0;
	int blue = 0x0000ff;
	int yellow = 0xffff00;
	void *mlx_window;
	void *mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, 800, 600, "Glory to Ukraine!");
	while (++f_idx <= 700)
	{
		while (++s_idx <= 250)
			mlx_pixel_put(mlx_connection, mlx_window, 50 + f_idx, 50 + s_idx,
					blue);
		s_idx = 0;
	}
	f_idx = -1;
	while (++f_idx <= 700)
	{
		while (++s_idx <= 250)
			mlx_pixel_put(mlx_connection, mlx_window, 50 + f_idx, 300 + s_idx,
					yellow);
		s_idx = 0;
	}
	mlx_loop(mlx_connection);
}