/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/24 19:39:51 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	ft_work_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_prepare_b(stack_a, (*stack_b)->value);
// 	ft_push_first_value(stack_b, stack_a, 'a');
// 	ft_reset_b(stack_b);
// 	// *amount -= 1;
// }

void	ft_fill_a(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	amount;

	while (*stack_b)
	{
		ft_find_biggest(stack_b, &position, &amount);
		if (position <= amount / 2)
			while (position--)
				ft_rotate(stack_b, 'b');
		else
			while (amount - position++)
				ft_reverse_rotate(stack_b, 'b');
		ft_push_first_value(stack_b, stack_a, 'a');
	}
}

void	ft_main_algorithm(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	f_position;
	int	l_position;
	int	max_position;
	int	step;

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
		// ft_printf("F_position: %d\nL_position: %d\n\n",
		// f_position,		l_position);
		if ((f_position < l_position) || (f_position == l_position
				&& f_position <= ft_count_amount(stack_a) / 2))
			while (--f_position)
				ft_rotate(stack_a, 'a');
		else
			while (l_position--)
				ft_reverse_rotate(stack_a, 'a');
		ft_push_first_value(stack_a, stack_b, 'b');
	}
	ft_fill_a(stack_a, stack_b);
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
