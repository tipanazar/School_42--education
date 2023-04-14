/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:21:10 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/14 15:25:19 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *str)
{
	size_t	len;
	char	*new_str;

	len = strlen(str) + 1;
	new_str = malloc(len);
	if (new_str == NULL)
	{
		return (NULL);
	}
	memcpy(new_str, str, len);
	return (new_str);
}
