/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:31:06 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/02 16:47:16 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	f;
	int	s;

	f = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[f] != '\0')
	{
		s = 0;
		while (str[f + s] == to_find[s] && str[f + s] != '\0')
		{
			if (to_find[s + 1] == '\0')
			{
				return (&str[f]);
			}
			s++;
		}
		f++;
	}
	return (0);
}

// int	main(void)
// {
// 	char first[] = "sec first ond";
// 	char second[] = "sec";

// 	printf("%s", ft_strstr(first, second));
// }