/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:21:24 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/14 15:23:13 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	needle_len;

	needle_len = strlen(needle);
	if (needle_len == 0)
	{
		return ((char *)haystack);
	}
	for (size_t i = 0; i < n && haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			if (strncmp(&haystack[i], needle, needle_len) == 0)
			{
				return ((char *)&haystack[i]);
			}
		}
	}
	return (NULL);
}
