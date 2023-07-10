/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/07 20:21:19 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_define_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Window");
	vars->idx = -1;
	vars->color = 0xffff00;
	vars->gap = 100;
}



void	ft_loop(t_vars *vars)
{
	(void)vars;
}

void	ft_render(t_vars *vars)
{
	vars->img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel,
			&vars->line_length, &vars->endian);
	ft_loop(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}

// int	main(void)
// {
// 	t_vars vars;

// 	ft_define_vars(&vars);
// 	ft_render(&vars);
// 	mlx_hook(vars.win, 2, 1L << 0, ft_handle_key, &vars);
// 	mlx_hook(vars.win, 17, 0, ft_close, &vars);
// 	mlx_mouse_hook(vars.win, ft_mouse_handler, &vars);
// 	mlx_loop(vars.mlx);
// }

#include <stdio.h>
#include <complex.h>

int main() {
    double complex a = 3 + 2 * I;
    double complex b = 1.5 - 0.5 * I;

    double complex sum = a + b;
    double complex product = a * b;

    printf("Сума: %.2f + %.2fi\n", creal(sum), cimag(sum));
    printf("Добуток: %.2f + %.2fi\n", creal(product), cimag(product));

    return 0;
}
