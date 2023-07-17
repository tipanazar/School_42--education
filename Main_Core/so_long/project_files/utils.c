/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:37 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/17 17:44:53 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_you_won_process(t_vars *vars)
{
	ft_printf("You won!\n");
	ft_clear_all(vars);
	exit(0);
}

void	ft_throw_error(char *error, t_vars *vars)
{
	ft_printf("%s\n", error);
	ft_clear_all(vars);
	exit(1);
}

void	ft_define_vars(t_vars *vars)
{
	vars->texture_size = 64;
	vars->collectibles = 0;
	vars->movements = 0;
	vars->mlx = NULL;
	vars->win = NULL;
}

void	ft_clear_all(t_vars *vars)
{
	if (vars->mlx && vars->win)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	ft_free_char_arr(vars->mapdata);
}
