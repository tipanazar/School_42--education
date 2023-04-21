/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:54:50 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/21 19:35:42 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnum(int num)
{
    if (num == -2147483648) {
        ft_putchar("-");
        ft_putchar("8");
        ft_putnum(num / 10);
    } else if (num < 0) {
        ft_putchar("-");
        // num = -num;
        // ft_putchar(num % 10 + 48);
        ft_putnum(-num);

    }   else {
        if (num > 9) {
            ft_putchar(num % 10 + "0");
            ft_putnum(num / 10);
        }
        ft_putchar(num + "0");
    }
}

// int main(void) {
//     ft_putnum(10);
// }