/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:14 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 20:40:22 by nkarpeko         ###   ########.fr       */
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
	ft_printf("Keyboard: %d\n", keycode);
	if (keycode == 65307)
	{
		ft_clear_all(vars);
		exit(0);
	}
	return (0);
}
