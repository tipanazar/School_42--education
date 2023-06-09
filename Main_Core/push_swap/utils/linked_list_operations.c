/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:56 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/09 18:48:15 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_create_stack(t_stack **list, int argc, char **args_arr)
{
	t_stack	*new_node;
	t_stack	*prev_node;

	prev_node = NULL;
	while (args_arr[--argc] && argc)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->value = ft_atol(args_arr[argc]);
		new_node->next = *list;
		new_node->prev = prev_node;
		if (*list)
			(*list)->prev = new_node;
		*list = new_node;
	}
}

void	ft_go_to_beggining(t_stack **list)
{
	while (*list && (*list)->prev)
		*list = (*list)->prev;
}

void	ft_print_list(t_stack *list)
{
	t_stack	*current;

	current = list;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	ft_free_list(t_stack *list)
{
	t_stack	*current;
	t_stack	*next;

	current = list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
