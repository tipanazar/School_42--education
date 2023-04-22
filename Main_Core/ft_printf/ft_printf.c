/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:04:13 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/22 20:29:51 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		idx;
	int		length;

	length = 0;
	idx = -1;
	va_start(args, str);
	while (str[++idx])
	{
		if (str[idx] == '%' && ft_type_identifier(str[idx + 1]))
			ft_type_distributor_middleware(args, str[++idx], &length);
		else
		{
			ft_putchar_fd(str[idx], 1);
			length++;
		}
	}
	va_end(args);
	return (1); //! AMOUNT OF CHARACTERS WERE PRINTED
}

int	main(void)
{
	// ft_printf("%s: %d\n", "Works?", 111);
	ft_printf("%s\n", "Works?");
}