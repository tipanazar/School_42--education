/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/22 21:09:35 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_work_b(t_stack **stack_a, t_stack **stack_b, int *amount)
// {
// 	ft_prepare_b(stack_b, (*stack_a)->value);
// 	ft_push_first_value(stack_a, stack_b, 'b');
// 	ft_reset_b(stack_b);
// 	*amount -= 1;
// }

void	ft_main_algorithm(t_stack **stack_a, t_stack **stack_b)
{

	
	(void) stack_a;
	(void) stack_b;
	
}

// void	ft_sort_three_algorithm(t_stack **list)
// {
// 	if ((*list)->value > (*list)->next->value
// 		&& (*list)->value < (*list)->next->next->value)
// 		ft_swap_first_two(list, 'a');
// 	else if ((*list)->value < (*list)->next->value
// 		&& (*list)->value > (*list)->next->next->value)
// 		ft_reverse_rotate(list, 'a');
// 	else if ((*list)->next->value < (*list)->value
// 		&& (*list)->next->value > (*list)->next->next->value)
// 	{
// 		ft_swap_first_two(list, 'a');
// 		ft_reverse_rotate(list, 'a');
// 	}
// 	else if ((*list)->next->value > (*list)->value
// 		&& (*list)->next->value > (*list)->next->next->value)
// 	{
// 		ft_swap_first_two(list, 'a');
// 		ft_rotate(list, 'a');
// 	}
// 	else if ((*list)->value > (*list)->next->value
// 		&& (*list)->value > (*list)->next->next->value)
// 		ft_rotate(list, 'a');
// }
