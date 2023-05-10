/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:45:57 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/10 16:31:45 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_str_converter(char *str)
{
	int		idx;
	int		base;
	char	bit;
	int		control;
	int		result;

	idx = 7;
	while (str[idx])
	{
		base = 1;
		control = idx;
		result = 0;
		while (base <= 128)
		{
			bit = str[control];
			if (bit == '1')
				result += base;
			base *= 2;
			control--;
		}
		ft_printf("%c", result);
		idx += 8;
	}
}

void	ft_message_handler(int sig)
{
	static int	idx;
	static char	c[8];

	if (sig == SIGUSR1)
		c[idx] = '1';
	else if (sig == SIGUSR2)
		c[idx] = '0';
	idx++;
	if (idx == 8)
	{
		idx = 0;
		ft_str_converter(c);
	}
}

int	main(void)
{
	ft_printf("Pid: %d\n", getpid());
	signal(SIGUSR1, ft_message_handler);
	signal(SIGUSR2, ft_message_handler);

	while (1)
		sleep(1);
	return (0);
}
