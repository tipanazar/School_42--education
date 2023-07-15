/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/15 19:20:04 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*img;
	// char	*addr;
	void	*mlx;
	void	*win;
	int		texture_size;
	char	**mapdata;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		collectibles;
	// int		score;
	// int		current_score;
	// void	*wall;
	// void	*exit;
	// void	*items;
	// void	*player;
	// int		enemy_x;
	// int		enemy_y;
	// int		game_over;
}			t_vars;

int			ft_handle_key(int keycode, t_vars *vars);
int			ft_close_win(t_vars *vars);
void		ft_define_vars(t_vars *vars);
void		ft_render(t_vars *vars);
void		ft_throw_error(char *error, t_vars *vars);
void		ft_read_map(t_vars *vars, char *map_path);
int			ft_count_lines_fd(char *map_path);
void		ft_clear_all(t_vars *vars);
void		ft_move_player_x(t_vars *vars, int position);
void		ft_move_player_y(t_vars *vars, int position);

#endif