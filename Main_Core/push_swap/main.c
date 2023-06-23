/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tipanazar <tipanazar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:51:46 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/23 20:48:40 by tipanazar        ###   ########.fr       */
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
	ft_check_is_sort(argv);
	//&
	// if (argc == 4)
	// 	ft_sort_three_algorithm(&stack_a);
	// // else if (argc == 6)
	// // 	medium_sort();
	// else
		ft_main_algorithm(&stack_a, &stack_b, argc);
	//&
	ft_printf("\nNew_A: ");
	ft_print_list(stack_a);
	ft_printf("New_B: ");
	ft_print_list(stack_b);
	//*
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}
