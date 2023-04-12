/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:06:17 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/01/30 16:28:06 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int num)
{
	int		first;
	int		second;
	char	char_first;
	char	char_second;

	first = num / 10;
	second = num % 10;
	char_first = first + '0';
	char_second = second + '0';
	write(1, &char_first, 1);
	write(1, &char_second, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_putchar(first);
			write(1, " ", 1);
			ft_putchar(second);
			if (first == 98 && second == 99)
			{
				break ;
			}
			write(1, ", ", 2);
			second++;
		}
		first++;
	}
}

// char	main(void)
// {
// 	ft_print_comb2();
// }
