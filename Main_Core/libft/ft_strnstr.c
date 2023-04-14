/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:21:24 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/14 15:57:24 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, int n)
{
	int	needle_len;
	int	idx;

	needle_len = ft_strlen(needle);
	idx = 0;
	if (needle_len == 0)
	{
		return ((char *)haystack);
	}
	while (idx < n && haystack[idx] != '\0')
	{
		if (haystack[idx] == needle[0])
		{
			if (ft_strncmp(&haystack[idx], needle, needle_len) == 0)
			{
				return ((char *)&haystack[idx]);
			}
		}
		idx++;
	}
	return (NULL);
}
