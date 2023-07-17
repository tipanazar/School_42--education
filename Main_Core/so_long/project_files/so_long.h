/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/17 18:53:03 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars
{
	void	*img;
	void	*mlx;
	void	*win;
	int		texture_size;
	char	**mapdata;
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		movements;
	char	*map_path;
}			t_vars;

int			ft_handle_key(int keycode, t_vars *vars);
int			ft_close_win(t_vars *vars);
void		ft_define_vars(t_vars *vars);
void		ft_render(t_vars *vars);
void		ft_throw_error(char *error, t_vars *vars);
void		ft_read_map(t_vars *vars);
int			ft_count_lines_fd(char *map_path);
void		ft_clear_all(t_vars *vars);
void		ft_move_player_x(t_vars *vars, int position);
void		ft_move_player_y(t_vars *vars, int position);
void		ft_you_won_process(t_vars *vars);
void		ft_map_checker(t_vars *vars);

#endif