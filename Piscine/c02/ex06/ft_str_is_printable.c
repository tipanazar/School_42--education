/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:39:05 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/01 18:58:08 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	idx;
	int	result;

	result = 1;
	idx = 0;
	while (str[idx])
	{
		if (!(str[idx] >= 32 && str[idx] <= 126))
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
// 	char string[] = "";
// //	char string[1];
// 	printf("%d", ft_str_is_printable(string));
// }