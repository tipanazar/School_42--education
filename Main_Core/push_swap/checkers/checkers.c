/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:49:03 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/27 19:14:03 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_throw_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_atol_middleware(const char *str, long *idx)
{
	while (str[*idx] == 32 || (str[*idx] >= 9 && str[*idx] <= 13))
		*idx += 1;
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;
	long	idx;

	sign = 1;
	result = 0;
	idx = 0;
	ft_atol_middleware(str, &idx);
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	if (!(str[idx] >= '0' && str[idx] <= '9'))
		ft_throw_err();
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		result *= 10;
		result += str[idx] - 48;
		idx++;
	}
	if (str[idx] && !(str[idx] >= '0' && str[idx] <= '9'))
		ft_throw_err();
	return (result * sign);
}

void	ft_check_is_sort(char **argv)
{
	int	idx;
	int	flag;

	idx = 0;
	flag = 1;
	while (argv[++idx])
	{
		if (argv[idx + 1] && ((ft_atol(argv[idx]) > ft_atol(argv[idx + 1]))))
			flag = 0;
	}
	if (flag)
		exit(0);
}

void	ft_checker(int argc, char **argv)
{
	int	idx;

	while (argv[--argc] && argc)
	{
		idx = -1;
		while (argv[argc][++idx])
			if ((argv[argc][idx] <= '0' && argv[argc][idx] >= '9')
				&& !(argv[argc][idx] == '-' && !idx))
				ft_throw_err();
		if (ft_atol(argv[argc]) < INT_MIN || ft_atol(argv[argc]) > INT_MAX)
			ft_throw_err();
	}
	while (argv[++argc])
	{
		idx = 0;
		while (argv[++idx])
			if ((ft_atol(argv[argc]) == ft_atol(argv[idx])) && (idx != argc))
				ft_throw_err();
	}
	if (argc < 3)
		exit(0);
}
