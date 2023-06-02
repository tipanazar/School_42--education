/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:51 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/02 20:20:11 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_first_two(t_stack **list, int stack_name)
{
	t_stack	*saver;

	if (*list && (*list)->next)
	{
		saver = (*list)->next;
		(*list)->next = (*list)->next->next;
		saver->next = *list;
		*list = saver;
	}
	if (stack_name)
		ft_printf("s%c\n", stack_name);
}

void	ft_push_first_value(t_stack **src, t_stack **dest, int stack_name)
{
	t_stack	*new_node;
	t_stack	*src_next;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!*src)
		return ;
	new_node->value = (*src)->value;
	new_node->next = *dest;
	new_node->prev = NULL;
	*dest = new_node;
	src_next = (*src)->next;
	free(*src);
	*src = src_next;
	if (stack_name)
		ft_printf("p%c\n", stack_name);
}

void	ft_rotate(t_stack **list, int stack_name)
{
	t_stack	*to_end;

	to_end = *list;
	*list = (*list)->next;
	(*list)->prev = NULL;
	to_end->next = NULL;
	while ((*list)->next)
		*list = (*list)->next;
	to_end->prev = *list;
	(*list)->next = to_end;
	while ((*list)->prev)
		*list = (*list)->prev;
	if (stack_name)
		ft_printf("r%c\n", stack_name);
}

void	ft_reverse_rotate(t_stack **list, int stack_name)
{
	t_stack	*to_beginning;

	while ((*list)->next->next)
		*list = (*list)->next;
	to_beginning = (*list)->next;
	to_beginning->prev = NULL;
	(*list)->next = NULL;
	while ((*list)->prev)
		*list = (*list)->prev;
	to_beginning->next = *list;
	(*list)->prev = to_beginning;
	*list = to_beginning;
	if (stack_name)
		ft_printf("rr%c\n", stack_name);
}
