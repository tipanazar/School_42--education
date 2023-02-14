#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_str_length(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

char	*ft_strcopy(char *str)
{
	int	idx;
	char	*string;

	idx = 0;
	string = (char *)malloc(ft_str_length(str) + 1);
	// if (!string)
	// 	return (NULL); 
	while (str[idx])
	{
		string[idx] = str[idx];
		idx++;
	}
	string[idx] = '\0';
	return (string);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int idx;
	struct s_stock_str *arr;

	// ac = ac + 0;
	arr = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!arr)
		return (NULL);
	idx = 0;
	while (idx < ac)
	{
		arr[idx].size = ft_str_length(av[idx]);
		arr[idx].str = av[idx];
		arr[idx].copy = ft_strcopy(av[idx]);
		idx++;
	}
	arr[idx] = (struct s_stock_str){0, 0, 0};
	return (arr);
}
