/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:04:13 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/23 13:14:03 by nkarpeko         ###   ########.fr       */
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
			ft_putcharl(str[idx], &length);
	}
	va_end(args);
	return (length); //! AMOUNT OF CHARACTERS WERE PRINTED
}

int	main(void)
{
	ft_printf("%s%d", "123456", 789);
	// ft_printf("%s\n", "Works?");
	// ft_printf("\nAmount of symbols: %d\n\n", ft_printf("\n%s: %d\n", "Works?",
	// 			111));
}
