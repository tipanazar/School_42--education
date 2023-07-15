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

void	ft_read_map(t_vars *vars, char *map_path)
{
	int		idx;
	int		fd;
	char	*line;
	int		arr_idx;

	arr_idx = 0;
	idx = -1;
	vars->collectibles = 0;
	vars->mapdata = (char **)malloc(sizeof(char *)
			* (ft_count_lines_fd(map_path) + 1));
	if (!vars->mapdata)
		ft_throw_error("Malloc error", vars);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		vars->mapdata[arr_idx] = (char *)malloc(sizeof(char) * (ft_strlen(line)
					+ 1));
		if (!vars->mapdata[arr_idx])
			ft_throw_error("Malloc error", vars);
		while (line[++idx] && line[idx] != '\n')
		{
			vars->mapdata[arr_idx][idx] = line[idx];
			if (line[idx] == 'C')
				vars->collectibles++;
		}
		vars->mapdata[arr_idx++][idx] = '\0';
		free(line);
		line = get_next_line(fd);
		idx = -1;
	}
	vars->mapdata[arr_idx] = NULL;
	close(fd);
}

void	ft_move_player_x(t_vars *vars, int position) // position == 1 or -1
{
	int x_idx = vars->player_x;
	int y_idx = vars->player_y;

	if ((vars->mapdata[y_idx][x_idx + position] == 'E' && !vars->collectibles)
		|| ((vars->mapdata[y_idx][x_idx + position] != '1')
			&& (vars->mapdata[y_idx][x_idx + position] != 'E')))
	{
		if (vars->mapdata[y_idx][x_idx + position] == 'C')
			vars->collectibles--;
		if (vars->mapdata[y_idx][x_idx + position] == 'E')
		{
			ft_printf("You won!\n");
			ft_clear_all(vars);
			exit(0);
		}
		vars->mapdata[y_idx][x_idx + position] = 'P';
		vars->mapdata[y_idx][x_idx] = '0';
		vars->player_x += position;
		vars->movements++;
		ft_printf("Movements: %d\n", vars->movements);
		mlx_clear_window(vars->mlx, vars->win);
		ft_render(vars);
	}
}

void	ft_move_player_y(t_vars *vars, int position) // position == 1 or -1
{
	int x_idx = vars->player_x;
	int y_idx = vars->player_y;
	if ((vars->mapdata[y_idx + position][x_idx] == 'E' && !vars->collectibles)
		|| ((vars->mapdata[y_idx + position][x_idx] != '1')
			&& (vars->mapdata[y_idx + position][x_idx] != 'E')))
	{
		if (vars->mapdata[y_idx + position][x_idx] == 'C')
			vars->collectibles--;
		if (vars->mapdata[y_idx + position][x_idx] == 'E')
		{
			ft_printf("You won!\n");
			ft_clear_all(vars);
			exit(0);
		}
		vars->mapdata[y_idx + position][x_idx] = 'P';
		vars->mapdata[y_idx][x_idx] = '0';
		vars->player_y += position;
		vars->movements++;
		ft_printf("Movements: %d\n", vars->movements);
		mlx_clear_window(vars->mlx, vars->win);
		ft_render(vars);
	}
}
