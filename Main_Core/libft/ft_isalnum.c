/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:51:30 by marvin            #+#    #+#             */
/*   Updated: 2023/04/14 15:24:33 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int symbol)
{
	if ((symbol >= 65 && symbol <= 90) || (symbol >= 97 && symbol <= 122)
		|| (symbol >= 0 && symbol <= 9))
		return (1);
	return (0);
}

int	main(void)
{
	printf("%d;", ft_isalnum('1'));
}
