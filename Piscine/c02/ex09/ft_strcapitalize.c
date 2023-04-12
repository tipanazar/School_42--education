/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:56:43 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/04 19:44:58 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>

void	ft_stringlowercase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'A' && str[idx] <= 'Z')
		{
			str[idx] = str[idx] + 32;
		}
		idx++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	idx;

	ft_stringlowercase(str);
	idx = 0;
	while (str[idx])
	{
		if (!idx && str[idx] >= 'a' && str[idx] <= 'z')
		{
			str[idx] = str[idx] - 32;
		}
		if (!(str[idx] >= 'a' && str[idx] <= 'z') && !(str[idx] >= 'A'
				&& str[idx] <= 'Z') && !(str[idx] >= '0' && str[idx] <= '9')
			&& (str[idx + 1] >= 'a' && str[idx + 1] <= 'z'))
		{
			str[idx + 1] = str[idx + 1] - 32;
		}
		idx++;
	}
	return (str);
}

// char	*ft_strcapitalize(char *str);

// int	main(void)
// {
// 	char str1[] = "alo maluco 42beleza!";
// 	char str2[] = "ALO MALUCO 42BELEZA!";
// 	char str3[] = "alo+ma|uco a2beleza!";
// 	char str4[] = "ALO+MALUCO*a2BELEZA!";
// 	char str5[] = "^uIv#= =9Hf~2y@F3A)FTzBgF";
// 	char str6[] = "tsR1|vn_WE}7X6{Vm2vQf(rG}qdnT`1,qH+n";

// 	printf("str1: %s\n", str1);
// 	ft_strcapitalize(str1);
// 	printf("str1_c: %s\n", str1);
// 	write(1, "\n", 1);
// 	printf("str2: %s\n", str2);
// 	ft_strcapitalize(str2);
// 	printf("str2_c: %s\n", str2);
// 	write(1, "\n", 1);
// 	printf("str3: %s\n", str3);
// 	ft_strcapitalize(str3);
// 	printf("str3_c: %s\n", str3);
// 	write(1, "\n", 1);
// 	printf("str4: %s\n", str4);
// 	ft_strcapitalize(str4);
// 	printf("str4_c: %s\n", str4);
// 	write(1, "\n", 1);
// 	printf("str5: %s\n", str5);
// 	ft_strcapitalize(str5);
// 	printf("str5_c: %s\n", str5);
// 	write(1, "\n", 1);
// 	printf("str6: %s\n", str6);
// 	ft_strcapitalize(str6);
// 	printf("str6_c: %s\n", str6);
// 	return (0);
// }