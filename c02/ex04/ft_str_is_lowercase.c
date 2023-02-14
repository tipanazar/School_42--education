/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:08:14 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/04 17:35:32 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>

int	ft_str_is_lowercase(char *str)
{
	int	idx;
	int	result;

	result = 1;
	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] >= 'a' && str[idx] <= 'z'))
		{
			result = 0;
			break ;
		}
		idx++;
	}
	return (result);
}

// int	main(void)
// {
// 	char *str1;
// 	char *str2;
// 	char *str3;
// 	char *str4;
// 	char *str5;

// 	str1 = calloc(10, sizeof(char));
// 	str2 = calloc(10, sizeof(char));
// 	str3 = calloc(10, sizeof(char));
// 	str4 = calloc(10, sizeof(char));
// 	str5 = calloc(10, sizeof(char));
// 	str1 = "abcdefghi";
// 	str2 = "Abcdefghi";
// 	str3 = "abc:efghi";
// 	str4 = "";
// 	str5 = "abcdefgh2";
// 	printf("str1: %s, is_lowercase: %d\n", str1, ft_str_is_lowercase(str1));
// 	printf("str2: %s, is_lowercase: %d\n", str2, ft_str_is_lowercase(str2));
// 	printf("str3: %s, is_lowercase: %d\n", str3, ft_str_is_lowercase(str3));
// 	printf("str4: %s, is_lowercase: %d\n", str4, ft_str_is_lowercase(str4));
// 	printf("str5: %s, is_lowercase: %d\n", str5, ft_str_is_lowercase(str5));
// 	return (0);
// }