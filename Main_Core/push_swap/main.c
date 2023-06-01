/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/05/31 18:33:00 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/31 18:33:00 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	ft_checker(argc, argv);
	stack *stack_a = NULL;
	// stack *stack_b = NULL;
	ft_create_stack(&stack_a, argc, argv);
	printf("Stack_A: ");
	ft_print_list(stack_a);
	// ft_swap_first_two(&stack_a);
	// printf("\nSwapped: ");
	// ft_print_list(stack_a);
	ft_free_list(stack_a);
	return (0);
}
