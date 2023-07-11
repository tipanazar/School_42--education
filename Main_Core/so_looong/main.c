/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/11 17:55:07 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(void)
{
	t_vars vars;

	ft_define_vars(&vars);
	ft_render(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 0, ft_close, &vars);
	mlx_mouse_hook(vars.win, ft_mouse_handler, &vars);
	mlx_loop(vars.mlx);
}
