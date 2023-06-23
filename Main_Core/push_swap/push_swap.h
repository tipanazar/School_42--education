/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:08:31 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/23 20:35:50 by tipanazar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "limits.h"

typedef struct s_stack
{
	int				value;
	int				position;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				ft_checker(int argc, char **argv);
void				ft_check_is_sort(char **argv);
void				ft_create_stack(t_stack **list, int argc, char **args_arr);
void				ft_go_to_beggining(t_stack **list);
void				ft_print_list(t_stack *head);
void				ft_free_list(t_stack *list);
void				ft_swap_first_two(t_stack **list, int t_stack_name);
void	ft_swap_first_two_both_stacks(t_stack **first,
									t_stack **second);
void				ft_push_first_value(t_stack **src, t_stack **dest,
						int t_stack_name);
void				ft_rotate(t_stack **list, int t_stack_name);
void				ft_rotate_both(t_stack **first, t_stack **second);
void				ft_reverse_rotate(t_stack **list, int t_stack_name);
void				ft_reverse_rotate_both(t_stack **first, t_stack **second);
//&
void				ft_main_algorithm(t_stack **stack_a, t_stack **stack_b,
						int argc);
int					ft_find_next(t_stack **list, int max_position,
						int *f_position, int *l_position);
void				ft_prepare_b(t_stack **list, int value);
void				ft_reset_b(t_stack **list);
// void				ft_sort_three_algorithm(t_stack **stack_a);
// int					ft_find_smallest(t_stack **list, int *total,
// int *biggest);

#endif