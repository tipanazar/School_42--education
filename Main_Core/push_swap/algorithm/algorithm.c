/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/14 12:37:46 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_main_algorithm(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	total;
// 	int	smallest;
// 	int	position;

// 	while ((*stack_a)->next)
// 	{
// 		position = ft_find_smallest(stack_a, &total, &smallest);
// 		ft_move_to_top(stack_a, total, position, smallest);
// 		ft_push_first_value(stack_a, stack_b, 'b');
// 	}
// 	while ((*stack_b))
// 	{
// 		ft_push_first_value(stack_b, stack_a, 'a');
// 	}
// }

void	ft_main_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	amount;
	int	average;
	int	idx;

	// int	position;
	(void)stack_b;
	while (*stack_a)
	{
		if (ft_find_next_lower_average(stack_a, average) == -1 && amount <= 20)
			break ;
		ft_find_average(stack_a, &amount, &average);
		idx = 0;
		while (*stack_a && idx < 20 && ft_find_next_lower_average(stack_a,
				average) != -1)
		{
			if ((*stack_a)->value <= average)
			{
				ft_prepare_b(stack_b, (*stack_a)->value);
				ft_push_first_value(stack_a, stack_b, 'b');
				ft_reset_b(stack_b);
				amount--;
				idx++;
				continue ;
			}
			if (ft_find_next_lower_average(stack_a, average) <= amount / 2)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}
	}
	// while ((*stack_b))
	// {
	// 	ft_push_first_value(stack_b, stack_a, 'a');
	// }
}
