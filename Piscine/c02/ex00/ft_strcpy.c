/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:24:20 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/01 18:57:48 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (src[idx] != '\0')
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char first[6] = "first";
// 	char second[7] = "second";
// 	ft_strcpy(first, second);
// 	printf("%s", first);
// 	printf("%s", second);
// }