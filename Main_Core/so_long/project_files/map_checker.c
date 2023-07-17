/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:49:46 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/17 18:16:45 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_type(char ch, t_vars *vars, int *exits, int *players)
{
	if (ch == 'C')
		vars->collectibles++;
	else if (ch == 'P')
		*players += 1;
	else if (ch == 'E')
		*exits += 1;
}

void	ft_check_path(char *path, t_vars *vars)
{
	char	**splitted_path;
	int		arr_idx;
	int		fd;

	splitted_path = ft_split(path, '.');
	arr_idx = -1;
	while (splitted_path[arr_idx + 1])
		arr_idx++;
	if (ft_strncmp(splitted_path[arr_idx], "ber", 4))
	{
		ft_free_char_arr(splitted_path);
		ft_throw_error("Map file is not .ber", vars);
	}
	ft_free_char_arr(splitted_path);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_throw_error("Map file not found", vars);
	close(fd);
}

void	ft_map_checker_middleware(t_vars *vars, int *exits, int *players)
{
	int	idx;
	int	arr_idx;

	idx = -1;
	arr_idx = 0;
	while (vars->mapdata[arr_idx][++idx])
		if (vars->mapdata[arr_idx][idx] != '1')
			ft_throw_error("Map is not closed", vars);
	while (vars->mapdata[++arr_idx + 1])
	{
		idx = 0;
		if (vars->mapdata[arr_idx][0] != '1')
			ft_throw_error("Map is not closed", vars);
		while (vars->mapdata[arr_idx][++idx + 1])
			ft_check_type(vars->mapdata[arr_idx][idx], vars, exits, players);
		if (vars->mapdata[arr_idx][idx] != '1')
			ft_throw_error("Map is not closed", vars);
	}
	idx = -1;
	while (vars->mapdata[arr_idx][++idx])
		if (vars->mapdata[arr_idx][idx] != '1')
			ft_throw_error("Map is not closed", vars);
}

void	ft_map_checker(t_vars *vars, char *path)
{
	int	idx;
	int	arr_idx;
	int	exits;
	int	players;

	idx = -1;
	arr_idx = 0;
	exits = 0;
	players = 0;
	ft_check_path(path, vars);
	ft_read_map(vars, path);
	ft_map_checker_middleware(vars, &exits, &players);
	if (exits != 1)
		ft_throw_error("Map is not valid, check amount of exits", vars);
	else if (players != 1)
		ft_throw_error("Map is not valid, check amount of players", vars);
	else if (vars->collectibles == 0)
		ft_throw_error("Map is not valid, check amount of collectibles", vars);
}
