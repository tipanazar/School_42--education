/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:22:58 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/21 20:39:46 by nkarpeko         ###   ########.fr       */
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

int	ft_find_doubles_in_num_arr(int *arr, int desired_val)
{
	int	idx;

	idx = -1;
	while (arr[++idx])
		if (arr[idx] == desired_val)
			return (1);
	return (0);
}

int	*ft_fill_arr_with_smallest(t_stack **list)
{
	int	*smallest_nums_arr;
	int	idx;
	int	amount;

	idx = -1;
	if (ft_find_amount(list) > 20)
		amount = 20;
	else
		amount = ft_find_amount(list);
	smallest_nums_arr = (int *)malloc(sizeof(int) * amount);
	if (!smallest_nums_arr)
		return (NULL);
	while (++idx < amount)
		smallest_nums_arr[idx] = 2147483647;
	// ft_printf("Amount: %d\n", amount);	
	while (1)
	{
		idx = -1;
		while (++idx < amount)
		{
			if ((smallest_nums_arr[idx] > (*list)->value)
				&& !ft_find_doubles_in_num_arr(smallest_nums_arr,
					(*list)->value))
				smallest_nums_arr[idx] = (*list)->value;
		}
		if (!(*list)->next)
			break ;
		*list = (*list)->next;
	}
	ft_go_to_beggining(list);
	return (smallest_nums_arr);
}

// int	ft_find_quarter(t_stack **list, int *amount)
// {
// 	long 	total;
// 	t_stack	*current;

// 	total = 0;
// 	current = *list;
// 	*amount = 0;
// 	while (current)
// 	{
// 		total += current->value;
// 		*amount += 1;
// 		current = current->next;
// 	}
// 	return (total / *amount / 2);
// }

// int	ft_find_next_lower_average(t_stack **list, int average)
// {
// 	int		idx;
// 	int		flag;
// 	t_stack	*current;

// 	flag = 0;
// 	idx = 0;
// 	current = *list;
// 	while (current)
// 	{
// 		if (current->value <= average)
// 		{
// 			flag = 1;
// 			break ;
// 		}
// 		idx++;
// 		current = current->next;
// 	}
// 	if (flag)
// 		return (idx);
// 	else
// 		return (-1);
// }

// void	ft_prepare_b(t_stack **list, int value)
// {
// 	int		amount;
// 	int		position;
// 	t_stack	*current;

// 	amount = ft_find_amount(list);
// 	if (!amount)
// 		return ;
// 	position = 0;
// 	current = *list;
// 	while (current)
// 	{
// 		if (current->value < value)
// 			break ;
// 		current = current->next;
// 		position++;
// 	}
// 	ft_prepare_b_middleware(list, position, amount);
// }

// void	ft_reset_b(t_stack **list)
// {
// 	int		amount;
// 	int		position;
// 	int		idx;
// 	int		biggest;
// 	t_stack	*current;

// 	position = 0;
// 	idx = 0;
// 	current = *list;
// 	amount = ft_find_amount(list);
// 	biggest = current->value;
// 	while (current)
// 	{
// 		if (current->value > biggest)
// 		{
// 			biggest = current->value;
// 			position = idx;
// 		}
// 		current = current->next;
// 		idx++;
// 	}
// 	ft_reset_b_middleware(list, position, amount);
// }
