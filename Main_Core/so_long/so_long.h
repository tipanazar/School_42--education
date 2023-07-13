/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/13 13:16:42 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1500
# define HEIGHT 1500

// #define WIDTH 800
// #define HEIGHT 600
# define MAX_ITERATIONS 1000

typedef struct s_vars
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*win;

}			t_vars;

typedef struct s_game
{
	int		height;
	int		width;
	int		player_position_x;
	int		player_position_y;
	int		score;
	int		current_score;
	char	**mapdata;
	void	*wall;
	void	*exit;
	void	*items;
	void	*player;
	int		enemy_position_x;
	int		enemy_position_y;
	int		game_over;
}			t_game;

// void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			ft_mouse_handler(int button, int x, int y, t_vars *vars);
int			ft_handle_key(int keycode, t_vars *vars);
int			ft_close(t_vars *vars);
void		ft_render(t_vars *vars);
//

#endif