/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:22:58 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/09 19:13:02 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// int	ft_find_smallest(t_stack **list, int *total, int *smallest)
// {
// 	t_stack	*current;
// 	int		position;

// 	current = *list;
// 	*total = 0;
// 	while (current)
// 	{
// 		if (!(*total) || current->value < *smallest)
// 		{
// 			*smallest = current->value;
// 			position = *total;
// 		}
// 		*total += 1;
// 		current = current->next;
// 	}
// 	return (position);
// }

// void	ft_move_to_top(t_stack **list, int total, int position, int value)
// {
// 	while ((*list)->value != value)
// 	{
// 		if (position <= total / 2)
// 			ft_rotate(list, 'a');
// 		else
// 			ft_reverse_rotate(list, 'a');
// 	}
// }

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