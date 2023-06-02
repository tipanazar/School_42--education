/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:49:03 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/02 09:47:22 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_throw_err(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	ft_checker(int argc, char **argv)
{
	int	idx;

	if (argc < 3)
		ft_throw_err();
	while (argv[--argc] && argc)
		if (ft_atoi(argv[argc]) < 0 || ft_atoi(argv[argc]) > 9)
			ft_throw_err();
	while (argv[++argc])
	{
		idx = 0;
		while (argv[++idx])
			if ((ft_atoi(argv[argc]) == ft_atoi(argv[idx])) && (idx != argc))
				ft_throw_err();
	}
}
