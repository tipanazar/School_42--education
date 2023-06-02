/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_combined_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:16:45 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/02 20:18:21 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_first_two_both_stacks(t_stack **first, t_stack **second)
{
	ft_swap_first_two(first, 0);
	ft_swap_first_two(second, 0);
	ft_printf("ss\n");
}

void	ft_rotate_both(t_stack **first, t_stack **second)
{
	ft_rotate(first, 0);
	ft_rotate(second, 0);
	ft_printf("rr\n");
}

void	ft_reverse_rotate_both(t_stack **first, t_stack **second)
{
	ft_reverse_rotate(first, 0);
	ft_reverse_rotate(second, 0);
	ft_printf("rrr\n");
}
