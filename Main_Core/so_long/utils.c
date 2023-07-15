/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:37 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/15 19:19:00 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_throw_error(char *error, t_vars *vars)
{
	ft_printf("%s\n", error);
	ft_clear_all(vars);
	exit(1);
}

void	ft_define_vars(t_vars *vars)
{
	vars->texture_size = 64;
	// vars->collectibles = 0;
	vars->width = ft_strlen(vars->mapdata[0]) * vars->texture_size;
	vars->height = ft_char_arr_length(vars->mapdata) * vars->texture_size;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Window");
}

void	ft_clear_all(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free_char_arr(vars->mapdata);
}
