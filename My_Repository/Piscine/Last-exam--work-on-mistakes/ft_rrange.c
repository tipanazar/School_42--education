#include <stdio.h>
#include <stdlib.h>

int	ft_range_size(int start, int end)
{
	int	size;

	size = start - end;
	if (!size)
		return (size);
	if (size < 0)
		return (-size + 1);
	return (size + 1);
}

int	*ft_rrange(int start, int end)
{
	int	idx;
	int	size;
	int	*arr;

	idx = 0;
	size = ft_range_size(start, end);
	if (!size)
	{
		arr = (int *)malloc(sizeof(int));
		arr[0] = 0;
		return (arr);
	}
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	if (start < end)
	{
		while (end >= start)
		{
			arr[idx] = end;
			end--;
			idx++;
		}
	}
	else
	{
		while (end <= start)
		{
			arr[idx] = end;
			end++;
			idx++;
		}
	}
	return (arr);
}

// #include <stdlib.h>
// #include <stdio.h>
// int		ft_abs(int x)
// {
// 	if (x < 0)
// 		return (-x);
// 	return (x);
// }

// int		*ft_rrange(int start, int end)
// {
// 	int i;
// 	int *tab;

// 	i = 0;
// 	tab = (int*)malloc(sizeof(int) * ft_abs(end - start) + 1);
// 	while (end > start)
// 	{
// 		tab[i] = end;
// 		end--;
// 		i++;
// 	}
// 	tab[i] = end;
// 	while (end < start)
// 	{
// 		tab[i] = end;
// 		end++;
// 		i++;
// 	}
// 	tab[i] = end;
// 	return (tab);
// }

int	main(void)
{
	int idx = 0;
	int start = 5;
	int end = 5;
	int size = ft_range_size(start, end);
	// int size = ft_abs(start - end) + 1;
	int *arr = ft_rrange(start, end);
	while (idx < size)
	{
		if (idx + 1 == size)
		{
			printf("%d;\n", arr[idx]);
		}
		else
		{
			printf("%d, ", arr[idx]);
		}
		idx++;
	}
	printf("\n");
}