/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:48:10 by gsilva            #+#    #+#             */
/*   Updated: 2023/05/30 17:08:39 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_chr
{
	int		y;
	int		x;
	int		width;
	int		height;
	void	*img;
}	t_chr;

typedef struct s_image
{
	void	*chr_left;
	void	*chr_right;
	void	*floor;
	void	*wall;
	void	*colec;
	void	*exit;
	int		width;
	int		height;
}	t_image;

typedef struct s_map
{
	char	**map;
	int		c;
	int		_c;
	int		e;
	int		_e;
	int		p;
}	t_map;

typedef struct s_game
{
	int		moves;
	int		map_lines;
	void	*mlx;
	void	*win;
}	t_game;

int		check_map(void);

int		keyhook(int keycode);

int		top_bot_check(char *line, size_t len);

int		mid_check(char *line, int x);

int		get_lines(int fd);

int		close_win(int keycode);

void	fill_map(void);

void	path_check(int y, int x);

void	obj_check(char c, int y, int x);

void	create_map(char *path);

void	create_img(void);

void	create_win(void);

void	close_game(void);

t_game	*game(void);

t_map	*map(void);

t_chr	*chr(void);

t_image	*img(void);

#endif