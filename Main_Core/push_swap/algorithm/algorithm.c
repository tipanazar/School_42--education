/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/23 20:38:52 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_work_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_prepare_b(stack_b, (*stack_a)->value);
	ft_push_first_value(stack_a, stack_b, 'b');
	ft_reset_b(stack_b);
	// *amount -= 1;
}

void	ft_main_algorithm(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	f_position;
	int	l_position;
	int	max_position;
	int	step;

	(void)stack_b;
	step = 1;
	if (argc < 251)
		max_position = 20;
	else
		max_position = 45;
	while (*stack_a)
	{
		if (!ft_find_next(stack_a, max_position * step, &f_position,
				&l_position))
		{
			step++;
			continue ;
		}
		if (f_position < l_position)
			while (--f_position)
				ft_rotate(stack_a, 'a');
		else
			while (l_position--)
				ft_reverse_rotate(stack_a, 'a');
		ft_work_b(stack_a, stack_b);	
		// break;
	}
	while(*stack_b)
		ft_push_first_value(stack_b, stack_a, 'a');
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
