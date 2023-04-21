/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:04:13 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/21 20:48:18 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		idx;
	// int		len;

	// len = 0;
	idx = -1;
	va_start(args, str);
	// printf("%d\n", va_arg(args, int));
	// printf("%d", va_arg(args, int));
	while (str[++idx])
	{
		if (str[idx] == '%' && ft_type_identifier(str[idx + 1]))
			ft_type_distributor_middleware(args, str[idx + 1]);
		else
			// ft_putchar(str[idx]);
			ft_putchar_fd(str[idx], 1);
	}
	va_end(args);
	return (1); //! AMOUNT OF CHARACTERS WERE PRINTED
	// return (len);
}

// int	main(void)
// {
// 	ft_printf("%s", "test");
// 	// ft_printf("test");
// 	// ft_strlen("test");
// }