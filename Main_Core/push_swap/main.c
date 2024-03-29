/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:51:46 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/06/27 19:49:03 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	ft_checker(argc, argv);
	ft_check_is_sort(argv);
	stack_a = NULL;
	stack_b = NULL;
	ft_create_stack(&stack_a, argc, argv);
	if (argc == 4)
		ft_sort_three_algorithm(&stack_a);
	else if (argc == 6)
		ft_sort_five_algorithm(&stack_a, &stack_b);
	else
		ft_main_algorithm(&stack_a, &stack_b, argc);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}
// ft_printf("\nNew_A: ");
// ft_print_list(stack_a);
// ft_printf("New_B: ");
// ft_print_list(stack_b);