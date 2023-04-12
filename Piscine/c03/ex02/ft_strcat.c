/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:19:45 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/02 16:45:04 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	f_idx;
	int	s_idx;

	f_idx = 0;
	s_idx = 0;
	while (dest[f_idx] != '\0')
	{
		f_idx++;
	}
	while (src[s_idx] != '\0')
	{
		dest[f_idx] = src[s_idx];
		f_idx++;
		s_idx++;
	}
	dest[f_idx] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char first[] = "first";
// 	char second[] = "second";

// 	printf("%s", ft_strcat(first, second));
// }