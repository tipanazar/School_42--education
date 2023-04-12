/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:27:45 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/02 20:16:05 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	f_idx;
	unsigned int	s_idx;

	f_idx = 0;
	s_idx = 0;
	while (dest[f_idx] != '\0')
	{
		f_idx++;
	}
	while (s_idx < nb && src[s_idx] != '\0')
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

// 	printf("%s", ft_strncat(first, second, 3));
// }