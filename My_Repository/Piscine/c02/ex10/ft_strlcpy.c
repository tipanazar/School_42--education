/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:36:23 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/05 15:35:59 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	if (size)
	{
		while (src[idx] && idx < (size - 1))
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	while (src[idx])
		idx++;
	return (idx);
}

// int	main(void)
// {
// 	int src_size;
// 	char *src;
// 	char *dest;

// 	src = calloc(11, sizeof(char));
// 	dest = calloc(8, sizeof(char));
// 	src = "alo galera";
// 	src_size = ft_strlcpy(dest, src, 8);
// 	printf("src: %s\n", src);
// 	printf("dest: %s\n", dest);
// 	printf("src_size: %d\n", src_size);
// 	return (0);
// }