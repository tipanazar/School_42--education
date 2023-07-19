/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:49:46 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/19 18:39:30 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_path(t_vars *vars)
{
	char	**splitted_path;
	int		arr_idx;
	int		fd;

	splitted_path = ft_split(vars->map_path, '.');
	arr_idx = -1;
	while (splitted_path[arr_idx + 1])
		arr_idx++;
	if (ft_strncmp(splitted_path[arr_idx], "ber", 4))
	{
		ft_free_char_arr(splitted_path);
		ft_throw_error("Map file is not .ber", vars);
	}
	ft_free_char_arr(splitted_path);
	fd = open(vars->map_path, O_RDONLY);
	if (fd == -1)
		ft_throw_error("Map not found", vars);
	close(fd);
}

void	ft_check_map_side(t_vars *vars, int arr_idx)
{
	int	idx;

	idx = -1;
	while (vars->mapdata[arr_idx][++idx])
		if (vars->mapdata[arr_idx][idx] != '1')
			ft_throw_error("Map is not closed", vars);
}

void	ft_map_checker_middleware(t_vars *vars, int *exits, int *players)
{
	int	idx;
	int	arr_idx;

	idx = -1;
	arr_idx = 0;
	ft_check_map_side(vars, arr_idx);
	while (vars->mapdata[++arr_idx + 1])
	{
		idx = 0;
		if (vars->mapdata[arr_idx][0] != '1')
			ft_throw_error("Map is not closed", vars);
		while (vars->mapdata[arr_idx][++idx + 1])
		{
			ft_check_type(vars->mapdata[arr_idx][idx], vars, exits, players);
			if (vars->mapdata[arr_idx][idx] == 'P')
			{
				vars->player_x = idx;
				vars->player_y = arr_idx;
			}
		}
		if (vars->mapdata[arr_idx][idx] != '1')
			ft_throw_error("Map is not closed", vars);
	}
	ft_check_map_side(vars, arr_idx);
}

void	ft_check_is_map_playable(t_vars *vars, int exits)
{
	t_floodfill	floodfill;

	floodfill.map = ft_read_map(vars);
	floodfill.collectibles = vars->collectibles;
	floodfill.exits = exits;
	ft_flood_fill(&floodfill, vars->player_x, vars->player_y);
	ft_free_char_arr(floodfill.map);
	if (floodfill.collectibles || floodfill.exits)
		ft_throw_error("Map is not playable", vars);
}

void	ft_map_checker(t_vars *vars)
{
	size_t	map_len;
	int		arr_idx;
	int		exits;
	int		players;

	map_len = 0;
	arr_idx = 0;
	exits = 0;
	players = 0;
	ft_check_path(vars);
	vars->mapdata = ft_read_map(vars);
	ft_map_checker_middleware(vars, &exits, &players);
	if (exits != 1)
		ft_throw_error("Map is not valid, check amount of exits", vars);
	else if (players != 1)
		ft_throw_error("Map is not valid, check amount of players", vars);
	else if (vars->collectibles == 0)
		ft_throw_error("Map is not valid, check amount of collectibles", vars);
	map_len = ft_strlen(vars->mapdata[0]);
	while (vars->mapdata[++arr_idx])
		if (map_len != ft_strlen(vars->mapdata[arr_idx]))
			ft_throw_error("Map size is invalid", vars);
	vars->width = ft_strlen(vars->mapdata[0]) * vars->texture_size;
	vars->height = ft_char_arr_length(vars->mapdata) * vars->texture_size;
	ft_check_is_map_playable(vars, exits);
}
