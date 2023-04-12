/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:04:32 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/08 17:33:12 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int ac, char **av)
{
	if (ac > 0)
	{
		ft_putstr(av[0]);
	}
	write(1, "\n", 1);
	return (0);
}
