/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:44:30 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/01 19:00:47 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
		{
			str[idx] = str[idx] - 32;
		}
		idx++;
	}
	return (str);
}

// int	main(void)
// {
// 	char string[] = "BsmBIGsmfds324324allBsM";
// 	// char string[1];
// 	printf("%s", ft_strupcase(string));
// }