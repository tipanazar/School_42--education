/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:35:30 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/08 18:31:24 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	int	sum;

	sum = nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb > 1)
	{
		sum *= ft_recursive_factorial(nb - 1);
	}
	return (sum);
}

// int	main(void)
// {
// 	int nb;
// 	int res;

// 	nb = -5;
// 	while (nb <= 10)
// 	{
// 		res = ft_recursive_factorial(nb);
// 		printf("> n = %d, n! = %d\n", nb, res);
// 		nb++;
// 	}
// 	return (0);
// }