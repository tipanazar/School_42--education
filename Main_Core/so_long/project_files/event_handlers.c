/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:14 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/17 17:44:16 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(t_vars *vars)
{
	ft_clear_all(vars);
	exit(0);
}

int	ft_handle_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		ft_clear_all(vars);
		exit(0);
	}
	else if (keycode == 119 || keycode == 65362)
		ft_move_player_y(vars, -1);
	else if (keycode == 100 || keycode == 65363)
		ft_move_player_x(vars, 1);
	else if (keycode == 115 || keycode == 65364)
		ft_move_player_y(vars, 1);
	else if (keycode == 97 || keycode == 65361)
		ft_move_player_x(vars, -1);
	return (0);
}
