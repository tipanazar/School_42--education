/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:56 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/01 17:11:43 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_create_stack(stack **head, int argc, char **args_arr)
{
	stack	*new_node;

	while (args_arr[--argc] && argc)
	{
		new_node = (stack *)malloc(sizeof(stack));
		new_node->value = ft_atoi(args_arr[argc]);
		new_node->next = *head;
		*head = new_node;
	}
}

void	ft_print_list(stack *head)
{
	stack	*current;

	current = head;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	ft_free_list(stack *list)
{
	stack	*current;
	stack	*next;

	current = list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
