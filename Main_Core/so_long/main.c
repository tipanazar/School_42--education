/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:49 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 20:38:52 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_return_id(char ch)
{
	if (ch == '0')
		return (NULL);
	else if (ch == '1')
		return ("./files/textures/grass.xpm");
	else if (ch == 'C')
		return ("./files/textures/canister.xpm");
	else if (ch == 'P')
		return ("./files/textures/w221.xpm");
	else if (ch == 'E')
		return ("./files/textures/autobanh.xpm");
	else
		return (NULL);
}

void	ft_loop(t_vars *vars, t_game *game, char *map, int line)
{
	int	pos;
	int	idx;
	char *path;

	pos = 0;
	idx = -1;
	(void)game;
	while (map[++idx])
	{
		path = ft_return_id(map[idx]);
		if (path)
		{
			vars->img = mlx_xpm_file_to_image(vars->mlx, path,
					&vars->texture_size, &vars->texture_size);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img, pos, line);
			mlx_destroy_image(vars->mlx, vars->img);
			// free(vars->img);
		}
		pos += 64;
	}
}

void	ft_render(t_vars *vars, t_game *game)
{
	int	idx;
	int	line;

	idx = -1;
	line = 0;
	while (vars->mapdata[++idx])
	{
		ft_loop(vars, game, vars->mapdata[idx], line);
		line += 64;
	}
}

void	ft_read_map(t_vars *vars, char *map_path)
{
	int		idx;
	int		fd;
	char	*line;
	int		arr_idx;

	arr_idx = 0;
	idx = -1;
	vars->mapdata = (char **)malloc(sizeof(char *)
			* (ft_count_lines_fd(map_path) + 1));
	if (!vars->mapdata)
		ft_throw_error("Malloc error");
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		vars->mapdata[arr_idx] = (char *)malloc(sizeof(char) * (ft_strlen(line)
					+ 1));
		if (!vars->mapdata[arr_idx])
			ft_throw_error("Malloc error");
		while (line[++idx] && line[idx] != '\n')
			vars->mapdata[arr_idx][idx] = line[idx];
		vars->mapdata[arr_idx++][idx] = '\0';
		free(line);
		line = get_next_line(fd);
		idx = -1;
	}
	vars->mapdata[arr_idx] = NULL;
	close(fd);
}

int	main(void)
{
	t_game	game;
	t_vars	vars;


	ft_read_map(&vars, "./files/maps/test_map.ber");
	ft_define_vars(&vars, &game);
	ft_render(&vars, &game);
	mlx_hook(vars.win, 2, 1L << 0, ft_handle_key, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_win, &vars);
	mlx_loop(vars.mlx);

	// ft_free_char_arr(game.mapdata);
	return (0);
}
