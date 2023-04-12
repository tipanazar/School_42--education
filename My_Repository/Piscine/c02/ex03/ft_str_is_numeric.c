/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:03:57 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/01 18:57:57 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	idx;
	int	result;

	result = 1;
	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
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
// 	char string[] = "03984983w246328648";
// //	char string[1];
// 	printf("%d", ft_str_is_numeric(string));
// }