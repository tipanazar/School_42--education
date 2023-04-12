/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:16:22 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/01/31 18:54:49 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (*str)
	{
		idx++;
		str++;
	}
	return (idx);
}

// int	main(void)
// {
// 	printf("%d", ft_strlen("7 chars"));
// }