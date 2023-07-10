/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:38:37 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/07/07 19:51:07 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	hsv_to_rgb(double h, double s, double v, double rgb[3])
{
	int	i;

	double f, p, q, t;
	if (s == 0)
	{
		rgb[0] = v;
		rgb[1] = v;
		rgb[2] = v;
		return ;
	}
	h /= 60;
	i = (int)h;
	f = h - i;
	p = v * (1 - s);
	q = v * (1 - s * f);
	t = v * (1 - s * (1 - f));
	switch (i)
	{
	case 0:
		rgb[0] = v;
		rgb[1] = t;
		rgb[2] = p;
		break ;
	case 1:
		rgb[0] = q;
		rgb[1] = v;
		rgb[2] = p;
		break ;
	case 2:
		rgb[0] = p;
		rgb[1] = v;
		rgb[2] = t;
		break ;
	case 3:
		rgb[0] = p;
		rgb[1] = q;
		rgb[2] = v;
		break ;
	case 4:
		rgb[0] = t;
		rgb[1] = p;
		rgb[2] = v;
		break ;
	default:
		rgb[0] = v;
		rgb[1] = p;
		rgb[2] = q;
		break ;
	}
}
