/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:48:06 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/13 23:14:08 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	*arr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
	{
		*range = 0;
		return (-1);
	}
	*range = arr;
	idx = 0;
	while (min < max)
	{
		arr[idx] = min;
		min++;
		idx++;
	}
	return (idx);
}

// int		main(void)
// {
// 	int res;
// 	int offset;
// 	int *range;

// 	res = ft_ultimate_range(&range, 0, 8);
// 	if (res == -1)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	offset = 0;
// 	while (offset < 8)
// 	{
// 		printf("%d ", range[offset]);
// 		offset++;
// 	}
// 	printf("\nres: %d", res);
// 	printf("\n");

// 	int *arr1;
// 	int *arr2;
// 	int *arr3;
// 	int *arr4;
// 	int *arr5;
// 	int *arr6;
// 	int size1;
// 	int size2;
// 	int size3;
// 	int size4;
// 	int size5;
// 	int size6;

// 	size1 = ft_ultimate_range(&arr1, 1, 2);
// 	size2 = ft_ultimate_range(&arr2, -1, 2);
// 	size3 = ft_ultimate_range(&arr3, -3, -1);
// 	size4 = ft_ultimate_range(&arr4, -2, -3);
// 	size5 = ft_ultimate_range(&arr5, 0, 10);
// 	size6 = ft_ultimate_range(&arr6, -2, 0);

// 	offset = 0;
// 	while (offset < 1)
// 	{
// 		printf("%d ", arr1[offset]);
// 		offset++;
// 	}
// 	printf("| min %d ", 1);
// 	printf("| max %d ", 2);
// 	printf("| size %d", size1);
// 	printf("\n");
// 	offset = 0;
// 	while (offset < 3)
// 	{
// 		printf("%d ", arr2[offset]);
// 		offset++;
// 	}
// 	printf("| min %d ", -1);
// 	printf("| max %d ", 2);
// 	printf("| size %d", size2);
// 	printf("\n");
// 	offset = 0;
// 	while (offset < 2)
// 	{
// 		printf("%d ", arr3[offset]);
// 		offset++;
// 	}
// 	printf("| min %d ", -3);
// 	printf("| max %d ", -1);
// 	printf("| size %d", size3);
// 	printf("\n");
// 	offset = 0;
// 	while (offset < 10)
// 	{
// 		printf("%d ", arr5[offset]);
// 		offset++;
// 	}
// 	printf("| min %d ", -2);
// 	printf("| max %d ", -3);
// 	printf("| size %d", size5);
// 	printf("\n");
// 	offset = 0;
// 	while (offset < 2)
// 	{
// 		printf("%d ", arr6[offset]);
// 		offset++;
// 	}
// 	printf("| min %d ", -2);
// 	printf("| max %d ", 0);
// 	printf("| size %d", size6);
// 	return (0);
// }