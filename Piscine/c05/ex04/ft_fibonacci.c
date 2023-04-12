/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:14:48 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/08 13:15:16 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

// int	main(void)
// {
// 	int res;
// 	int index;

// 	index = 0;
// 	while (index < 12)
// 	{
// 		res = ft_fibonacci(index);
// 		printf("%d, ", res);
// 		index++;
// 	}
// 	res = ft_fibonacci(index);
// 	printf("%d\n", res);
// 	return (0);
// }