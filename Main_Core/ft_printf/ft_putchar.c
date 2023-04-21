/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:16:36 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/21 16:02:47 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char *ch)
{
		write(1, ch, sizeof(ch));
	printf("%lu\n", sizeof(ch));
		// write(1, ch, 16);
}

// int main (void) {
// 	char test[] = "test string 123";
// 	// char test[] = "te";
// 	ft_putchar(test);
// }