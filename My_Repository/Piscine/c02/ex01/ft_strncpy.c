/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:42:55 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/04 17:32:21 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	idx;
	unsigned int	idx2;

	idx = 0;
	idx2 = idx;
	while (idx < n && src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	while (idx < n)
	{
		dest[idx] = '\0';
		idx++;
	}
	return (dest);
}

// void	ft_strncpy_test(char *dest, char *ft_dest, char *src, unsigned int n)
// {
// 	char	*res;
// 	char	*ft_res;

// 	res = strncpy(dest, src, n);
// 	ft_res = ft_strncpy(ft_dest, src, n);
// 	if (ft_res != ft_dest)
// 		printf("> KO, return (addres doesn't match *ft_dest, expected: %p, got:
// 				%p\n", ft_res, ft_dest));
// 	else if (strcmp(res, ft_res) != 0)
// 		printf("> KO, string has not been copied properly, expected: %s, got:
// 				%s\n", res, ft_res);
// 	else
// 		printf("> OK, result: %s\n", ft_res);
// }

// int	main(void)
// {
// 	unsigned int n;
// 	char *src;
// 	char *dest;
// 	char *ft_dest;

// 	src = calloc(100, sizeof(char));
// 	dest = calloc(100, sizeof(char));
// 	ft_dest = calloc(100, sizeof(char));
// 	n = 0;
// 	srand(0);
// 	while (n < 99)
// 	{
// 		src[n] = rand() % 90 + '0' > 126 ? '.' : rand() % 90 + '0';
// 		n++;
// 	}
// 	src[n] = '\0';
// 	n = 0;
// 	while (n < 100)
// 	{
// 		ft_strncpy_test(dest, ft_dest, src, n);
// 		n++;
// 	}
// 	while (n < 99)
// 	{
// 		src[n] = rand() % 90 + '0' > 126 ? '.' : rand() % 90 + '0';
// 		dest[n] = rand() % 88 + '0' > 126 ? '.' : rand() % 88 + '0';
// 		n++;
// 	}
// 	src[n] = '\0';
// 	n = 0;
// 	while (n < 100)
// 	{
// 		ft_strncpy_test(dest, ft_dest, src, n);
// 		n++;
// 	}
// 	return (0);
// }