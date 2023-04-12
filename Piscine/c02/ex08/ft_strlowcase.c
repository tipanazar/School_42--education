/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:53:34 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/01 19:00:43 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
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
	return (str);
}

// int	main(void)
// {
// 	char string[] = "BsmBIGsmfds324324allBsM";
// 	// char string[1];
// 	printf("%s", ft_strlowcase(string));
// }