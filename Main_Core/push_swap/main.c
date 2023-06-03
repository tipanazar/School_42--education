/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:51:46 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/03 16:30:32 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_checker(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_create_stack(&stack_a, argc, argv);
	ft_create_stack(&stack_b, argc, argv);
	//*
	ft_printf("stack_a: ");
	ft_print_list(stack_a);
	ft_printf("stack_b: ");
	ft_print_list(stack_b);
	//&
	// ft_swap_first_two(&stack_b, 'b');
	// ft_swap_first_two_both_stacks(&stack_a, &stack_b);
	// ft_push_first_value(&stack_a, &stack_b, 'b');
	// ft_rotate(&stack_b, 'b');
	// ft_rotate(&stack_b, 'b');
	// ft_rotate_both(&stack_a, &stack_b);
	// ft_reverse_rotate(&stack_b, 'b');
	// ft_reverse_rotate(&stack_b, 'b');
	// ft_reverse_rotate_both(&stack_a, &stack_b);
	//&
	// ft_swap_first_two_both_stacks(&stack_a, &stack_b);
	// ft_swap_first_two_both_stacks(&stack_a, &stack_b);
	// ft_swap_first_two_both_stacks(&stack_a, &stack_b);
	// ft_swap_first_two_both_stacks(&stack_a, &stack_b);
	ft_push_first_value(&stack_a, &stack_b, 'b');
	ft_push_first_value(&stack_a, &stack_b, 'b');
	ft_push_first_value(&stack_a, &stack_b, 'b');
	ft_push_first_value(&stack_a, &stack_b, 'b');
	ft_push_first_value(&stack_b, &stack_a, 'a');
	ft_push_first_value(&stack_b, &stack_a, 'a');
	ft_push_first_value(&stack_b, &stack_a, 'a');
	ft_push_first_value(&stack_b, &stack_a, 'a');
	// ft_rotate_both(&stack_a, &stack_b);
	// ft_rotate_both(&stack_a, &stack_b);
	// ft_rotate_both(&stack_a, &stack_b);
	// ft_rotate_both(&stack_a, &stack_b);
	// ft_reverse_rotate_both(&stack_a, &stack_b);
	// ft_reverse_rotate_both(&stack_a, &stack_b);
	// ft_reverse_rotate_both(&stack_a, &stack_b);
	// ft_reverse_rotate_both(&stack_a, &stack_b);
	//*
	ft_printf("\nNew_A: ");
	ft_print_list(stack_a);
	ft_printf("New_B: ");
	ft_print_list(stack_b);
	//*
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}
