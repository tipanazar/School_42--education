/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:20:43 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/14 15:57:24 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, int num)
{
	unsigned char		*p_dest;
	unsigned char	*p_src;

	p_dest = dest;
	p_src = src;
	while (num--)
	{
		*p_dest++ = *p_src++;
	}
	return (dest);
}
