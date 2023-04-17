/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 20:04:01 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/17 20:07:04 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char ch, int fd)
{
	write(fd, &ch, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		ft_putchar(*s++, fd);
}
