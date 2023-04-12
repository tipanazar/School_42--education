/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:21:22 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/01 18:57:55 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	idx;
	int	result;

	result = 1;
	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] >= 'a' && str[idx] <= 'z') && !(str[idx] >= 'A'
				&& str[idx] <= 'Z'))
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
// 	char string[] = "stRing";
// 	// char string[1];
// 	printf("%d", ft_str_is_alpha(string));
// }