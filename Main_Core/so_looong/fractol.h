/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:04:47 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/07 19:53:44 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1500

// #define WIDTH 800
// #define HEIGHT 600
#define MAX_ITERATIONS 1000


typedef struct s_vars
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		idx;
	int		color;
	int		gap;
	//
    double real;
    double imag;
}			t_vars;

void		my_mlx_pixel_put(t_vars *data, int x, int y, int color);
int			ft_mouse_handler(int button, int x, int y, t_vars *vars);
int			ft_handle_key(int keycode, t_vars *vars);
int			ft_close(t_vars *vars);
void		ft_render(t_vars *vars);
//
void	hsv_to_rgb(double h, double s, double v, double rgb[3]);


#endif