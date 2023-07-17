/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/17 18:52:48 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_return_id(char ch)
{
	if (ch == '1')
		return ("../files/textures/wall.xpm");
	else if (ch == 'C')
		return ("../files/textures/canister.xpm");
	else if (ch == 'P')
		return ("../files/textures/w221.xpm");
	else if (ch == 'E')
		return ("../files/textures/autobanh.xpm");
	else if (ch == '0')
		return ("../files/textures/background.xpm");
	else
		return (NULL);
}

void	ft_loop(t_vars *vars, char *map, int line)
{
	int		pos;
	int		idx;
	char	*path;

	pos = 0;
	idx = -1;
	while (map[++idx])
	{
		if (map[idx] == 'P')
		{
			vars->player_x = idx;
			vars->player_y = line / vars->texture_size;
		}
		path = ft_return_id(map[idx]);
		if (path)
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, path,
					&vars->texture_size, &vars->texture_size);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, pos, line);
			mlx_destroy_image(vars->mlx, vars->img);
		}
		pos += vars->texture_size;
	}
}

void	ft_render(t_vars *vars)
{
	int	idx;
	int	line;

	idx = -1;
	line = 0;
	while (vars->mapdata[++idx])
	{
		ft_loop(vars, vars->mapdata[idx], line);
		line += vars->texture_size;
	}
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_define_vars(&vars);
	if (argc != 2)
		ft_throw_error("Wrong amount of arguments", &vars);
	vars.map_path = ft_strjoin("../files/maps/", argv[1]);
	ft_map_checker(&vars);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height,
			"./so_long");
	ft_render(&vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
