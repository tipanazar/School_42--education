/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:13:03 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/19 18:02:53 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines_fd(char *map_path)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(map_path, O_RDONLY);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	ft_read_map_middleware(t_vars *vars, char **map, int fd)
{
	char	*line;
	int		idx;
	int		arr_idx;

	arr_idx = 0;
	idx = -1;
	line = get_next_line(fd);
	while (line)
	{
		map[arr_idx] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!map[arr_idx])
			ft_throw_error("Malloc error", vars);
		while (line[++idx] && line[idx] != '\n')
		{
			map[arr_idx][idx] = line[idx];
		}
		map[arr_idx++][idx] = '\0';
		free(line);
		line = get_next_line(fd);
		idx = -1;
	}
	map[arr_idx] = NULL;
}

char	**ft_read_map(t_vars *vars)
{
	int		fd;
	char	**map;

	if (!ft_count_lines_fd(vars->map_path))
	{
		ft_printf("Empty map\n");
		free(vars->map_path);
		exit(1);
	}
	map = (char **)malloc(sizeof(char *) * (ft_count_lines_fd(vars->map_path)
				+ 1));
	if (!map)
		ft_throw_error("Malloc error", vars);
	fd = open(vars->map_path, O_RDONLY);
	ft_read_map_middleware(vars, map, fd);
	close(fd);
	return (map);
}

void	ft_move_player_x(t_vars *vars, int position)
{
	int	x_idx;
	int	y_idx;

	x_idx = vars->player_x;
	y_idx = vars->player_y;
	if ((vars->mapdata[y_idx][x_idx + position] == 'E' && !vars->collectibles)
		|| ((vars->mapdata[y_idx][x_idx + position] != '1')
			&& (vars->mapdata[y_idx][x_idx + position] != 'E')))
	{
		if (vars->mapdata[y_idx][x_idx + position] == 'C')
			vars->collectibles--;
		if (vars->mapdata[y_idx][x_idx + position] == 'E')
			ft_you_won_process(vars);
		vars->mapdata[y_idx][x_idx + position] = 'P';
		vars->mapdata[y_idx][x_idx] = '0';
		vars->player_x += position;
		vars->movements++;
		ft_printf("Movements: %d\n", vars->movements);
		ft_render(vars);
	}
}

void	ft_move_player_y(t_vars *vars, int position)
{
	int	x_idx;
	int	y_idx;

	x_idx = vars->player_x;
	y_idx = vars->player_y;
	if ((vars->mapdata[y_idx + position][x_idx] == 'E' && !vars->collectibles)
		|| ((vars->mapdata[y_idx + position][x_idx] != '1')
			&& (vars->mapdata[y_idx + position][x_idx] != 'E')))
	{
		if (vars->mapdata[y_idx + position][x_idx] == 'C')
			vars->collectibles--;
		if (vars->mapdata[y_idx + position][x_idx] == 'E')
			ft_you_won_process(vars);
		vars->mapdata[y_idx + position][x_idx] = 'P';
		vars->mapdata[y_idx][x_idx] = '0';
		vars->player_y += position;
		vars->movements++;
		ft_printf("Movements: %d\n", vars->movements);
		ft_render(vars);
	}
}
