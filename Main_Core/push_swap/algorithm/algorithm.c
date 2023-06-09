/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/09 16:57:12 by nkarpeko         ###   ########.fr       */
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
	int idx;
	// int	position;
	(void) stack_b;
	while (*stack_a)
	{
		ft_find_average(stack_a, &amount, &average);
		idx = 0;
		while (*stack_a && idx < 20) {
			if((*stack_a)->value <= average) {
				ft_push_first_value(stack_a, stack_b, 'b');
				idx++;
			}
			*stack_a = (*stack_a)->next;
		}
		ft_go_to_beggining(stack_a);
	}
	// while ((*stack_b))
	// {
	// 	ft_push_first_value(stack_b, stack_a, 'a');
	// }
}
