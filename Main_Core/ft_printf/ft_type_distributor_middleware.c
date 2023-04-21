/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_distributor_middleware.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:22:30 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/21 16:01:27 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_distributor_middleware(va_list args, char ch)
{
	if (ch == 'c')
		ft_putchar(va_arg(args, char *));
	else if (ch == 's')
		ft_putchar(va_arg(args, char *));
	else if (ch == 'd')
		ft_putnum(va_arg(args, int));
}
