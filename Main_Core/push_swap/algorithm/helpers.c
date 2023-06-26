/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:30:50 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/26 17:41:23 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_count_amount(t_stack **list)
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

void	ft_find_biggest(t_stack **list, int *position, int *amount)
{
	t_stack	*current;
	int		biggest = INT_MIN;

	*amount = 0;
	*position = 0;
	current = *list;
	while (current)
	{
		if (current->value > biggest)
		{
			biggest = current->value;
			*position = *amount;
		}
		current = current->next;
		*amount += 1;
	}
}
