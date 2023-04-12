/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:37:21 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/01 19:02:22 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	idx;
	int	result;

	result = 1;
	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] >= 'A' && str[idx] <= 'Z'))
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
// 	char string[] = "ASDF";
// 	// char string[1];
// 	printf("%d", ft_str_is_uppercase(string));
// }