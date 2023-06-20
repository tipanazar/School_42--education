/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:49:03 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/20 15:44:10 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_throw_err(void)
{
	ft_printf("Error\n");
	exit(1);
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

	if (argc < 3)
		exit(0);
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
}
