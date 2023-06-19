/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:22:58 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/19 15:18:27 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_amount(t_stack **list)
{
	t_stack	*current;
	int		idx;

	idx = 0;
	current = *list;
	while (current)
	{
		idx++;
		current = current->next;
	}
	return (idx);
}

void	ft_find_average(t_stack **list, int *amount, int *average)
{
	long	total;
	t_stack	*current;

	total = 0;
	current = *list;
	*amount = 0;
	while (current)
	{
		total += current->value;
		*amount += 1;
		current = current->next;
	}
	*average = total / *amount;
}

int	ft_find_next_lower_average(t_stack **list, int average)
{
	int		idx;
	int		flag;
	t_stack	*current;

	flag = 0;
	idx = 0;
	current = *list;
	while (current)
	{
		if (current->value <= average)
		{
			flag = 1;
			break ;
		}
		idx++;
		current = current->next;
	}
	if (flag)
		return (idx);
	else
		return (-1);
}

void	ft_prepare_b(t_stack **list, int value)
{
	int		amount;
	int		position;
	t_stack	*current;

	amount = ft_find_amount(list);
	if (!amount)
		return ;
	position = 0;
	current = *list;
	while (current)
	{
		if (current->value < value)
			break ;
		current = current->next;
		position++;
	}
	// ft_printf("Value: %d\nPosition: %d\nAmount: %d\n", value, position,	amount);
	if (position && position <= amount / 2)
	{
		while (position--) //* pre-decrement issue??
		{
			ft_rotate(list, 'b');
		}
	}
	else if (position)
	{
		while (amount - position++) //* pre-decrement issue??
		{
			ft_reverse_rotate(list, 'b');
		}
	}
}

void	ft_reset_b(t_stack **list)
{
	int		amount;
	int		position;
	int		idx;
	int		biggest;
	t_stack	*current;

	position = 0;
	idx = 0;
	current = *list;
	amount = ft_find_amount(list);
	biggest = current->value;
	while (current)
	{
		if (current->value > biggest)
		{
			biggest = current->value;
			position = idx;
		}
		current = current->next;
		idx++;
	}
	// ft_printf("Position: %d\nBiggest: %d\nAmount: %d\n", position, biggest, amount);
	if (position && position <= amount / 2)
	{
		while (position--) //* pre-decrement issue??
		{
			ft_rotate(list, 'd');
		}
	}
	else if (position)
	{
		while (amount - position++) //* pre-decrement issue??
		{
			ft_reverse_rotate(list, 'd');
		}
	}
}

int	ft_find_smallest(t_stack **list, int *total, int *smallest)
{
	t_stack	*current;
	int		position;

	current = *list;
	*total = 0;
	while (current)
	{
		if (!(*total) || current->value < *smallest)
		{
			*smallest = current->value;
			position = *total;
		}
		*total += 1;
		current = current->next;
	}
	return (position);
}

void	ft_move_to_top(t_stack **list, int total, int position, int value)
{
	while ((*list)->value != value)
	{
		if (position <= total / 2)
			ft_rotate(list, 'a');
		else
			ft_reverse_rotate(list, 'a');
	}
}

void ft_sort_a(t_stack **stack_a, t_stack **stack_b)
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
}
