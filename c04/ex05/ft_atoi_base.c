/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:53:21 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/11 20:54:14 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_in_base(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (i);
	return (-1);
}

int	ft_baselen(char *base)
{
	int	size;

	size = -1;
	while (base[++size])
		if (base[size] == '+' || base[size] == '-' || base[size] == ' '
			|| ft_in_base(base[size], base + size + 1) >= 0 || (base[size] >= 9
				&& base[size] <= 13))
			return (0);
	return (size);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	sign;
	int	size;

	sign = 1;
	size = ft_baselen(base);
	if (size < 2)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	n = 0;
	i = ft_in_base(*str, base);
	while (i >= 0)
	{
		n = n * size + i;
		str++;
		i = ft_in_base(*str, base);
	}
	return (n * sign);
}

// #include <stdio.h>

// void	ft_atoi_base_test(char *str, char *base, int expected_number)
// {
// 	int	ft_buff;

// 	ft_buff = ft_atoi_base(str, base);
// 	if (ft_buff != expected_number)
// 		printf("> KO, expected: %d got: %d\n", expected_number, ft_buff);
// 	else
// 		printf("> OK, result: %d\n", ft_buff);
// }

// int	main(void)
// {
// 	// teste com bases binarias
// 	printf("Bases binarias:\n");
// 	ft_atoi_base_test("\n \t\r \v \f++++--1000,.fs", "01", 8);
// 	ft_atoi_base_test("\n \t\r \v \f++++--*/*/**,.fs", "/*", 43);
// 	// teste com bases octais
// 	printf("Bases octais:\n");
// 	ft_atoi_base_test("\n \t\r \v \f++-++--205,.fs", "01234567", -133);
// 	ft_atoi_base_test("\n \t\r \v \f+-+++--fdd,.fs", "abcdefgh", -347);
// 	// teste com bases decimais
// 	printf("Bases decimais:\n");
// 	ft_atoi_base_test("\n \t\r \v \f++-++--2147483648,.fs", "0123456789",
// 			-2147483648);
// 	ft_atoi_base_test("\n \t\r \v \f+-+++-+jjf,.fs", "abcdefghij", 995);
// 	// teste com bases hexadecimais
// 	printf("Bases hexadecimais:\n");
// 	ft_atoi_base_test("\n \t\r \v \f++-+-+--F0FA,.fs", "0123456789ABCDEF",
// 			61690);
// 	ft_atoi_base_test("\n \t\r \v \f+-+++-+ninc,.fs", "abcdefghijklmnop",
// 			55506);
// 	// teste com bases invalidas
// 	printf("Bases invalidas:\n");
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123456678", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\n", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\v", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\t", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\f", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123\r", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123 ", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123+", 0);
// 	ft_atoi_base_test("\n \t\r ++-++-123456,das", "0123-", 0);
// }