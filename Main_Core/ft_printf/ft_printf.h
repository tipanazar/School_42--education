/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:45:10 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/21 20:30:50 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
// - - - -
# include <stdarg.h>
# include <unistd.h>
# include "lib/libft.h"

int		ft_printf(const char *str, ...);
// void	ft_putchar(char *ch);
// void	ft_putnum(int num);
int		ft_type_identifier(char ch);
void	ft_type_distributor_middleware(va_list args, char ch);

#endif