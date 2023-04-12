/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:59:01 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/08 13:21:02 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	i = nb;
	while (!ft_is_prime(i))
		i++;
	return (i);
}

// int	main(void)
// {
// 	int ret;

// 	if ((ret = ft_find_next_prime(0)) != 2)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//prime after 0 is 2, got %i",
//		ret);
// 	else if ((ret = ft_find_next_prime(1)) != 2)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO
// , prime after 1 is 2, got %i",
//		ret);
// 	else if ((ret = ft_find_next_prime(2)) != 2)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
// prime after 2 is 2, got %i",
//		ret);
// 	else if ((ret = ft_find_next_prime(8)) != 11)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//prime after 8 is 11, got %i",
//		ret);
// 	else if ((ret = ft_find_next_prime(4)) != 5)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//prime after 4 is 5, got %i",
//		ret);
// 	else if ((ret = ft_find_next_prime(13)) != 13)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//prime after 4 is 5, got %i",
//		ret);
// 	else if ((ret = ft_find_next_prime(5982)) != 5987)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//prime after 5982 is 5987,
//		got%i", ret);
// 	else if ((ret = ft_find_next_prime(2000000000)) != 2000000011)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//		prime after 2000000000 is 2000000011, got %i", ret);
// 	else if ((ret = ft_find_next_prime(INT_MAX - 11)) != INT_MAX)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//prime after INT_MAX
//		- 11 is INT_MAX, got %i", ret);
// 	else if ((ret = ft_find_next_prime(-50)) != 2)
// 		printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\bKO,
//prime after -50 is 2, got %i",
//		ret);
// }