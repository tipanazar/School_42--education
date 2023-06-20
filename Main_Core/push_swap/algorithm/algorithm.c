/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/20 16:26:53 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_work_b(t_stack **stack_a, t_stack **stack_b, int *amount, int *idx)
{
	ft_prepare_b(stack_b, (*stack_a)->value);
	ft_push_first_value(stack_a, stack_b, 'b');
	ft_reset_b(stack_b);
	*amount -= 1;
	*idx += 1;
}

void	ft_main_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	amount;
	int	average;
	int	idx;

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
				ft_work_b(stack_a, stack_b, &amount, &idx);
			else if (ft_find_next_lower_average(stack_a, average) <= amount / 2)
				ft_rotate(stack_a, 'a');
			else
				ft_reverse_rotate(stack_a, 'a');
		}
	}
	ft_sort_a(stack_a, stack_b);
	while ((*stack_b))
		ft_push_first_value(stack_b, stack_a, 'a');
}

void	ft_sort_three_algorithm(t_stack **list)
{
	if ((*list)->value > (*list)->next->value
		&& (*list)->value < (*list)->next->next->value)
		ft_swap_first_two(list, 'a');
	else if ((*list)->value < (*list)->next->value
		&& (*list)->value > (*list)->next->next->value)
		ft_reverse_rotate(list, 'a');
	else if ((*list)->next->value < (*list)->value
		&& (*list)->next->value > (*list)->next->next->value)
	{
		ft_swap_first_two(list, 'a');
		ft_reverse_rotate(list, 'a');
	}
	else if ((*list)->next->value > (*list)->value
		&& (*list)->next->value > (*list)->next->next->value)
	{
		ft_swap_first_two(list, 'a');
		ft_rotate(list, 'a');
	}
	else if ((*list)->value > (*list)->next->value
		&& (*list)->value > (*list)->next->next->value)
		ft_rotate(list, 'a');
}
