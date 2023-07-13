/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 20:40:13 by nkarpeko         ###   ########.fr       */
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
	char	*addr;
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	int		texture_size;
	char	**mapdata;
}			t_vars;

typedef struct s_game
{
	int		height;
	int		width;
	int		player_position_x;
	int		player_position_y;
	int		score;
	int		current_score;
	void	*wall;
	void	*exit;
	void	*items;
	void	*player;
	int		enemy_position_x;
	int		enemy_position_y;
	int		game_over;
}			t_game;

int			ft_handle_key(int keycode, t_vars *vars);
int			ft_close_win(t_vars *vars);
void		ft_define_vars(t_vars *vars, t_game *game);
void		ft_render(t_vars *vars, t_game *game);
void		ft_throw_error(char *error);
int			ft_count_lines_fd(char *map_path);
void		ft_clear_all(t_vars *vars);

#endif