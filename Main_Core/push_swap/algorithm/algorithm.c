/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/21 20:11:59 by nkarpeko         ###   ########.fr       */
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
	int	*smallest_nums_arr;
	int	idx;

	smallest_nums_arr = ft_fill_arr_with_smallest(stack_a);
	idx = -1;
	ft_printf("Arr:\n");
	while (smallest_nums_arr[++idx])
	{
		ft_printf("%d ", smallest_nums_arr[idx]);
	}
	ft_printf("\n");
	(void) stack_b;
	// int	amount = ft_find_amount(stack_a);
	// // int	multiply_by;
	// // int	quarter;
	// // quarter = ft_find_quarter(stack_a, &amount);
	// // multiply_by = 1;
	// 	while (*stack_a) {
	// 		while (*stack_a && ft_find_next_lower_average(stack_a, quarter) !=
					// -1)
	// 		{
	// 			if ((*stack_a)->value <= quarter)
	// 				ft_work_b(stack_a, stack_b, &amount);
	// 			else if (ft_find_next_lower_average(stack_a, quarter) <= amount
						// / 2)
	// 				ft_rotate(stack_a, 'a');
	// 			else
	// 				ft_reverse_rotate(stack_a, 'a');
	// 		}
	// }
	// ft_sort_a(stack_a, stack_b);
	// while	((*stack_b))
	// 	ft_push_first_value(stack_b, stack_a, 'a');
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
