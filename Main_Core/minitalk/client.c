/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:46:07 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/19 20:10:17 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include <signal.h>

void	ft_message_handler(char *str, int pidserv)
{
	char	ch;
	int		idx;

	while (*str)
	{
		ch = *str++;
		idx = 7;
		while (idx >= 0)
		{
			if ((ch >> idx) & 1)
				kill(pidserv, SIGUSR2);
			else
				kill(pidserv, SIGUSR1);
			usleep(500);
			idx--;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Invalid input!\n");
		return (1);
	}
	ft_message_handler(argv[2], ft_atoi(argv[1]));
	return (0);
}
