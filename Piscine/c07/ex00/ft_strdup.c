/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:45:10 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/11 23:23:59 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		idx;

	idx = 0;
	while (src[idx])
		idx++;
	dest = (char *)malloc(sizeof(src) * idx);
	idx = 0;
	if (!dest)
		return (NULL);
	while (src[idx])
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char *str;
// 	char *str_copy;

// 	str = "Test string.";
// 	str_copy = ft_strdup(str);
// 	if (strcmp(str, str_copy) != 0)
// 		printf("KO, string is not the same.\n");
// 	else
// 		printf("OK.\n");
// 	str = "";
// 	str_copy = ft_strdup(str);
// 	if (strcmp(str, str_copy) != 0)
// 		printf("KO, string is not the same.\n");
// 	else
// 		printf("OK.\n");
// 	str = "eeeeeeee vida de gado";
// 	str_copy = ft_strdup(str);
// 	if (strcmp(str, str_copy) != 0)
// 		printf("KO, string is not the same.\n");
// 	else
// 		printf("OK.\n");
// 	return (0);
// }