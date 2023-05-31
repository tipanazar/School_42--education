/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:56 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/31 19:23:21 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#include "../push_swap.h"

	void	ft_create_stack(stack **head, char **args_arr)
	{
		int	idx;

		idx = 0;
		while (args_arr[++idx])
		{
			ft_stack_creator(head, atoi(args_arr[idx]));
		}
	}

	void	ft_stack_creator(stack **head, int value)
	{ //! move to ft_crate_stack
		stack	*newNode;

		newNode = (stack *)malloc(sizeof(stack));
		newNode->value = value;
		newNode->next = *head;
		*head = newNode;
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
