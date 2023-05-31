/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:08 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/30 17:12:14 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_chr	*chr(void)
{
	static t_chr	chr_struct;

	return (&chr_struct);
}

t_image	*img(void)
{
	static t_image	img_struct;

	return (&img_struct);
}

void	create_img(void)
{
	img()->width = 60;
	img()->height = 60;
	(img()->chr_left) = mlx_xpm_file_to_image(game()->mlx,
			"./assets/chr_left.xpm", &img()->width, &img()->height);
	(img()->chr_right) = mlx_xpm_file_to_image(game()->mlx,
			"./assets/chr_right.xpm", &img()->width, &img()->height);
	(img()->wall) = mlx_xpm_file_to_image(game()->mlx, "./assets/wall.xpm",
			&img()->width, &img()->height);
	(img()->floor) = mlx_xpm_file_to_image(game()->mlx, "./assets/floor.xpm",
			&img()->width, &img()->height);
	(img()->colec) = mlx_xpm_file_to_image(game()->mlx, "./assets/colec.xpm",
			&img()->width, &img()->height);
	(img()->exit) = mlx_xpm_file_to_image(game()->mlx, "./assets/exit.xpm",
			&img()->width, &img()->height);
	(chr()->img) = img()->chr_right;
}
