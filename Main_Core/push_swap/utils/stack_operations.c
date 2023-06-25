/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:51 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/25 18:53:58 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_first_two(t_stack **list, int stack_name)
{
	int	to_beginning_value;
	int	to_beginning_position;

	if (*list && (*list)->next)
	{
		to_beginning_value = (*list)->next->value;
		to_beginning_position = (*list)->next->position;
		(*list)->next->value = (*list)->value;
		(*list)->next->position = (*list)->position;
		(*list)->value = to_beginning_value;
		(*list)->position = to_beginning_position;
		if (stack_name)
			ft_printf("s%c\n", stack_name);
	}
}

void	ft_push_first_value(t_stack **src, t_stack **dest, int stack_name)
{
	t_stack	*to_beginning;

	if (*src)
	{
		if ((*src)->next)
			(*src)->next->prev = NULL;
		to_beginning = (*src)->next;
		(*src)->next = *dest;
		if (*dest)
			(*dest)->prev = *src;
		*dest = *src;
		*src = to_beginning;
		if (stack_name)
			ft_printf("p%c\n", stack_name);
	}
}

void	ft_rotate(t_stack **list, int stack_name)
{
	int	to_end_value;
	int	to_end_position;

	if (*list && (*list)->next)
	{
		to_end_value = (*list)->value;
		to_end_position = (*list)->position;
		while ((*list)->next)
		{
			(*list)->value = (*list)->next->value;
			(*list)->position = (*list)->next->position;
			*list = (*list)->next;
		}
		(*list)->value = to_end_value;
		(*list)->position = to_end_position;
		while ((*list)->prev)
			*list = (*list)->prev;
		if (stack_name)
			ft_printf("r%c\n", stack_name);
	}
}

void	ft_reverse_rotate(t_stack **list, int stack_name)
{
	int	to_beginning_value;
	int	to_beginning_position;

	if (*list && (*list)->next)
	{
		while ((*list)->next)
			*list = (*list)->next;
		to_beginning_value = (*list)->value;
		to_beginning_position = (*list)->position;
		while ((*list)->prev)
		{
			(*list)->value = (*list)->prev->value;
			(*list)->position = (*list)->prev->position;
			*list = (*list)->prev;
		}
		(*list)->value = to_beginning_value;
		(*list)->position = to_beginning_position;
		if (stack_name)
			ft_printf("rr%c\n", stack_name);
	}
}
