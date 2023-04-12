/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:08:30 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/08 18:28:26 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	sum;

	sum = 1;
	if (nb < 0)
		return (0);
	while (nb)
	{
		sum *= nb;
		nb--;
	}
	return (sum);
}

// int	main(void)
// {
// 	int n;
// 	int res;

// 	n = -5;
// 	while (n <= 10)
// 	{
// 		res = ft_iterative_factorial(n);
// 		printf("n = %d, n! = %d\n", n, res);
// 		n++;
// 	}
// 	return (0);
// }