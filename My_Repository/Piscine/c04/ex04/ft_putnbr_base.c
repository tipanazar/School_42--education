/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:23:23 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/02/11 20:52:10 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_in_base(char c, char *base)
{
	while (*base)
		if (c == *base++)
			return (1);
	return (0);
}

void	ft_print(unsigned int n, char *base, unsigned int idx)
{
	if (n > idx - 1)
	{
		ft_print(n / idx, base, idx);
		n %= idx;
	}
	ft_putchar(base[n]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	idx;

	idx = -1;
	while (base[++idx])
		if (base[idx] == '+' || base[idx] == '-' || base[idx] == ' '
			|| ft_in_base(base[idx], base + idx + 1) || (base[idx] >= 9
				&& base[idx] <= 13))
			return ;
	if (idx < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_print(-nbr, base, idx);
	}
	else
		ft_print(nbr, base, idx);
}

// int	main(void)
// {
// 	// base binaria
// 	printf("Bases binarias, n = 47. \"01\" e \"\\/\"\n");
// 	ft_putnbr_base(47, "01");
// 	ft_putchar('\n');
// 	printf("Esperado: 101111\n");
// 	ft_putnbr_base(47, "\\/");
// 	ft_putchar('\n');
// 	printf("Esperado: /\\////\n");
// 	// base 5
// 	printf("Bases 5, n = 36. \"01345\" e \"sd2ek\"\n");
// 	ft_putnbr_base(36, "01345");
// 	ft_putchar('\n');
// 	printf("Esperado: 131\n");
// 	ft_putnbr_base(36, "sd2ek");
// 	ft_putchar('\n');
// 	printf("Esperado: d2d\n");
// 	// base 10
// 	printf("Bases 10, n = %d. \"0123456789\" e \",.;\\][{}@#\"\n", INT_MIN);
// 	ft_putnbr_base(INT_MIN, "0123456789");
// 	ft_putchar('\n');
// 	printf("Esperado: -2147483648\n");
// 	ft_putnbr_base(INT_MIN, ",.;\\][{}@#");
// 	ft_putchar('\n');
// 	printf("Esperado: -;.]}]@\\{]@\n");
// 	// base 16
// 	printf("Bases 16, n =-65040. \"0123456789ABCDEF\"
// e \"jdlskmnMKZxVuzfa\"\n");
// 	ft_putnbr_base(-65040, "0123456789ABCDEF");
// 	ft_putchar('\n');
// 	printf("Esperado: -FE10\n");
// 	ft_putnbr_base(-65040, "jdlskmnMKZxVuzfa");
// 	ft_putchar('\n');
// 	printf("Esperado: -afdj\n");
// 	// base 0 e base 1, nao pode aparecer nada
// 	printf("Bases 0 e 1, nao deve aparecer nada, n = 256.\n");
// 	ft_putnbr_base(-29092, "0");
// 	ft_putnbr_base(-29092, "");
// 	return (0);
// }