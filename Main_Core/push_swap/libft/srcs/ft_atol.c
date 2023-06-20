/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:58:55 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/20 14:58:59 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;
	long	idx;

	sign = 1;
	result = 0;
	idx = 0;
	while (str[idx] == 32 || (str[idx] >= 9 && str[idx] <= 13))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result *= 10;
		result += str[idx] - 48;
		idx++;
	}
	return (result * sign);
}
