/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:22:58 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/27 19:17:17 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_next_first_loop(t_stack **list, int max_range, int max_range_amount,
		int *f_position)
{
	int	flag;

	flag = 0;
	while (1)
	{
		if ((max_range_amount && ((*list)->position < max_range))
			|| (!max_range_amount && ((*list)->position == max_range)))
		{
			flag = 1;
			break ;
		}
		*f_position += 1;
		if ((*list)->next)
			*list = (*list)->next;
		else
			break ;
	}
	return (flag);
}

int	ft_find_next_second_loop(t_stack **list, int max_range,
		int max_range_amount, int *l_position)
{
	int	flag;

	flag = 0;
	while (1)
	{
		if ((max_range_amount && ((*list)->position < max_range))
			|| (!max_range_amount && ((*list)->position == max_range)))
		{
			flag = 1;
			break ;
		}
		*l_position += 1;
		if ((*list)->prev)
			*list = (*list)->prev;
		else
			break ;
	}
	return (flag);
}

int	ft_find_next(t_stack **list, int max_range, int *f_position,
		int *l_position)
{
	int	flag;
	int	max_range_amount;

	max_range_amount = ft_amount_less_max_range(list, max_range);
	flag = 0;
	*f_position = 0;
	*l_position = 1;
	flag = ft_find_next_first_loop(list, max_range, max_range_amount,
			f_position);
	while ((*list)->next)
		*list = (*list)->next;
	flag = ft_find_next_second_loop(list, max_range, max_range_amount,
			l_position);
	ft_go_to_beggining(list);
	return (flag);
}

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
