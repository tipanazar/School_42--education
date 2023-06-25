/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:22:58 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/25 19:37:32 by nkarpeko         ###   ########.fr       */
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

int	ft_find_next(t_stack **list, int max_position, int *f_position,
		int *l_position)
{
	int	flag;

	flag = 0;
	*f_position = 0;
	*l_position = 1;
	while (1)
	{
		if ((*list)->position <= max_position)
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
	while ((*list)->next)
		*list = (*list)->next;
	while (1)
	{
		if ((*list)->position <= max_position)
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
	ft_go_to_beggining(list);
	return (flag);
}

void	ft_find_biggest(t_stack **list, int *position, int *amount)
{
	t_stack	*current;
	int		biggest;

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

