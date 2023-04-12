/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:32:53 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/01/31 18:53:08 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	f_idx;
	int	l_idx;
	int	tmp;

	f_idx = 0;
	l_idx = size - 1;
	while (f_idx < size / 2)
	{
		tmp = tab[f_idx];
		tab[f_idx] = tab[l_idx];
		tab[l_idx] = tmp;
		f_idx++;
		l_idx--;
	}
}

// int	main(void)
// {
// 	int	arr[5];

// 	arr[0] = 1;
// 	arr[1] = 2;
// 	arr[2] = 3;
// 	arr[3] = 4;
// 	arr[4] = 5;
// 	arr[5] = 6;
// 	ft_rev_int_tab(arr, 6);
// 	for (int idx = 0; idx < 6; idx++)
// 	{
// 		printf("%d", arr[idx]);
// 	}
// }
