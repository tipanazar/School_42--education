/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:11:54 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/23 15:39:12 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// void	ft_putaddress(unsigned long num, int *length)
// {
// 	if (!num)
// 		ft_putstrl("(nil)", length);
// 	else
// 	{
// 		if (num < 16)
// 		{
// 			ft_putstrl("0x", length);
// 			ft_putcharl("0123456789abcdef"[num % 16], length);
// 			return ;
// 		}
// 		ft_putaddress(num / 16, length);
// 		ft_putcharl("0123456789abcdef"[num % 16], length);
// 	}
// }

void	ft_putaddress(unsigned long addr, int *len)
{
	if (!addr)
		ft_putstrl("(nil)", len);
	else
	{
		if (addr < 16)
		{
			ft_putstrl("0x", len);
			ft_putcharl("0123456789abcdef"[addr % 16], len);
			return ;
		}
		ft_putaddress(addr / 16, len);
		ft_putcharl("0123456789abcdef"[addr % 16], len);
	}
}
