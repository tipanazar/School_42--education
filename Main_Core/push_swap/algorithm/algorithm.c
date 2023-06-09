/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/08 20:11:30 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_main_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	total;
	int	smallest;
	int	position;

	while ((*stack_a)->next)
	{
		position = ft_find_smallest(stack_a, &total, &smallest);
		ft_move_to_top(stack_a, total, position, smallest);
		ft_push_first_value(stack_a, stack_b, 'b');
	}
	while ((*stack_b))
	{
		ft_push_first_value(stack_b, stack_a, 'a');
	}
}
