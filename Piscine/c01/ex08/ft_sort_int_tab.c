/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:21:03 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/01/31 18:52:15 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	j;
	int	tmp;

	idx = 1;
	while (idx < size)
	{
		tmp = tab[idx];
		j = idx - 1;
		while (j >= 0 && tab[j] > tmp)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = tmp;
		idx++;
	}
}

// int	main(void)
// {
// 	int arr[5];

// 	arr[0] = 0;
// 	arr[1] = 5;
// 	arr[2] = 3;
// 	arr[3] = 3;
// 	arr[4] = 9;
// 	arr[5] = 1;
// 	ft_sort_int_tab(arr, 6);
// 	for (int idx = 0; idx < 6; idx++)
// 	{
// 		printf("%d", arr[idx]);
// 	}
// }