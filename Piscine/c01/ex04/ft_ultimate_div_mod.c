/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:13:33 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/01/31 18:57:22 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	int_num;

	int_num = *a / *b;
	*b = *a % *b;
	*a = int_num;
}

// int	main(void)
// {
// 	int a = 5;
// 	int b = 2;
// 	ft_ultimate_div_mod(&a, &b);
// 	printf("%d, %d", a, b);
// }