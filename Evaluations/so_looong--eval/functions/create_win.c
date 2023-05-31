/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:58:14 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/30 15:43:54 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_win(void)
{
	int		x;

	x = ft_strlen(map()->map[0]) - 1;
	(game()->win) = mlx_new_window(game()->mlx, x * 60,
			game()->map_lines * 60, "so_long");
}
