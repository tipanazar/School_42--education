/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_distributor_middleware.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:22:30 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/21 20:23:55 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_distributor_middleware(va_list args, char ch)
{
	if (ch == 'c')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (ch == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (ch == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
}
