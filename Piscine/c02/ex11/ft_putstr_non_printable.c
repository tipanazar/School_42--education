/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:22:21 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/06 13:17:50 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_prchar(unsigned char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				idx;
	unsigned char	ch;

	idx = 0;
	while (str[idx])
	{
		ch = str[idx];
		if (ch >= 32 && ch <= 126)
		{
			ft_prchar(ch);
		}
		else
		{
			ft_prchar('\\');
			ft_prchar("0123456789abcdef"[ch / 16]);
			ft_prchar("0123456789abcdef"[ch % 16]);
		}
		idx++;
	}
}

// int	main(void)
// {
// 	char str[] = "Coucou\ntu vas bien ?";
// 	//             Coucou\0atu vas bien ?
// 	ft_putstr_non_printable(str);
// 	return (0);
// }