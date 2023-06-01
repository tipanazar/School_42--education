/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:32:51 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/31 19:25:04 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap_first_two(stack **head)
{
	stack	*saver;

	if (*head && (*head)->next)
	{
		saver = (*head)->next;
		(*head)->next = (*head)->next->next;
		saver->next = *head;
		*head = saver;
	}
}
