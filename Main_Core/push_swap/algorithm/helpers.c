/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:22:58 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/24 19:25:08 by nkarpeko         ###   ########.fr       */
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
	*l_position = 0;
	while (1)
	{
		*f_position += 1;
		if ((*list)->position <= max_position)
		{
			flag = 1;
			break ;
		}
		if ((*list)->next)
			*list = (*list)->next;
		else
			break ;
	}
	while ((*list)->next)
		*list = (*list)->next;
	while (1)
	{
		*l_position += 1;
		if ((*list)->position <= max_position)
		{
			flag = 1;
			break ;
		}
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

// void	ft_prepare_b_middleware(t_stack **list, int position, int amount)
// {
// 	if (position && position <= amount / 2)
// 		while (position--)
// 			ft_rotate(list, 'b');
// 	else if (position)
// 		while (amount - position++)
// 			ft_reverse_rotate(list, 'b');
// }

// void	ft_prepare_b(t_stack **list, int value)
// {
// 	int		amount;
// 	int		position;
// 	t_stack	*current;

// 	amount = ft_count_amount(list);
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

// void	ft_reset_b_middleware(t_stack **list, int position, int amount)
// {
// 	if (position && position <= amount / 2)
// 		while (position--) //* pre-decrement issue??
// 			ft_rotate(list, 'd');
// 	else if (position)
// 		while (amount - position++) //* pre-decrement issue??
// 			ft_reverse_rotate(list, 'd');
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
// 	amount = ft_count_amount(list);
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
