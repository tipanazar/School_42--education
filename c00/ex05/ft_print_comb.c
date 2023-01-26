/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:14:35 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 22:14:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_comb(void)
{
    int first = '0';
    int second;
    int third;

    while (first <= '9')
    {
        second = first + 1;
        while (second <= '9')
        {
            third = second + 1;
            while (third <= '9')
            {
                write(1, &first, 1);
                write(1, &second, 1);
                write(1, &third, 1);

                if (first < '7')
                {
                    write(1, ", ", 2);
                }
                third++;
            }
            second++;
        }
        first++;
    }
}

int main(void)
{
    ft_print_comb();
}
