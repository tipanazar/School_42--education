/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:21:24 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/14 17:35:29 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *string, char *keyword, int n)
{
	int	keyword_len;
	int	idx;

	keyword_len = ft_strlen(keyword);
	idx = 0;
	if (!keyword_len)
		return ((char *)string);
	while (idx < n && string[idx] && (n - idx >= keyword_len))
	{
		if (string[idx] == *keyword && !ft_strncmp(&string[idx], keyword,
				keyword_len))
		{
			return ((char *)&string[idx]);
		}
		idx++;
	}
	return (NULL);
}
