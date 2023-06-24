/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:56 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/24 20:33:29 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_position(char **argv, int argc, int desired_val)
{
	int	position;

	position = 1;
	while (--argc)
		if (desired_val > ft_atol(argv[argc]))
			position++;
	return (position);
}

void	ft_create_stack(t_stack **list, int argc, char **args_arr)
{
	t_stack	*new_node;
	t_stack	*prev_node;
	int		idx;

	idx = argc;
	prev_node = NULL;
	while (--idx)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		new_node->value = ft_atol(args_arr[idx]);
		new_node->position = ft_find_position(args_arr, argc,
				ft_atol(args_arr[idx]));
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
		// printf("Value: %d\nPosit: %d\n", current->value, current->position);
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
