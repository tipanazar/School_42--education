/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:37 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 18:56:52 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_throw_error(char *error)
{
	ft_printf("%s\n", error);
	exit(1);
}

void	ft_define_vars(t_vars *vars, t_game *game)
{
	vars->width = ft_strlen(game->mapdata[0]) * 64;
	vars->height = ft_char_arr_length(game->mapdata) * 64;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "Window");
	vars->texture_size = 64;
}

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

// int ft_count_lines(char **map)
// {
// 	int		lines;

// 	lines = 0;
// 	while (map[lines])
// 		lines++;
// 	return (lines);
// }
