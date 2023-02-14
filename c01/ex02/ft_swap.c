/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:26:51 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/01/31 19:01:48 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	med;

	med = *a;
	*a = *b;
	*b = med;
}

// int	main(void)
// {
// 	int first = 1;
// 	int second = 2;
// 	ft_swap(&first, &second);
// 	printf("%d, %d", first, second);
// }