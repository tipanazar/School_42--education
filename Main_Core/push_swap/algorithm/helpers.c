/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:22:58 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/20 15:06:08 by nkarpeko         ###   ########.fr       */
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
	ft_prepare_b_middleware(list, position, amount);
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
	ft_reset_b_middleware(list, position, amount);
}
