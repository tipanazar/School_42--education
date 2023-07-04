/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/04 19:39:39 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
# include "./mlx_linux/mlx_int.h"

# define WIDTH 800
# define HEIGHT 600

typedef struct s_vars
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		f_idx;
	int		s_idx;
	int		blue;
	int		yellow;
	int		height;
	int		width;
}			t_vars;

void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			ft_mouse_handle(int button, int x, int y, t_vars *vars);
int			ft_handle_key(int keycode, t_vars *vars);
int			ft_close(t_vars *vars);
void		ft_render(t_vars *vars);

#endif