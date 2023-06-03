/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:08:31 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/03 18:44:30 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "limits.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				ft_checker(int argc, char **argv);
void				ft_create_stack(t_stack **list, int argc, char **args_arr);
void				ft_swap_first_two(t_stack **list, int t_stack_name);
void				ft_swap_first_two_both_stacks(t_stack **first,
									t_stack **second);
void				ft_push_first_value(t_stack **src, t_stack **dest,
						int t_stack_name);
void				ft_rotate(t_stack **list, int t_stack_name);
void				ft_rotate_both(t_stack **first, t_stack **second);
void				ft_reverse_rotate(t_stack **list, int t_stack_name);
void				ft_reverse_rotate_both(t_stack **first, t_stack **second);
void				ft_print_list(t_stack *head);
void				ft_free_list(t_stack *list);

#endif