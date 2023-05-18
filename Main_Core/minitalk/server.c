/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:45:57 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/18 21:59:13 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./lib/libft.h"
# include <signal.h>

void	ft_message_handler(int sig)
{
	static char	ascii;
	static int	grade;

	if (!grade)
		grade = 128;
	if (sig == SIGUSR2)
		ascii += grade;
	if (grade == 1)
	{
		ft_printf("%c", ascii);
		grade = 128;
		ascii = 0;
		return ;
	}
	grade /= 2;
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
