
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int value;
	struct s_stack *next;
} stack;

void	ft_create_stack(stack **head, char **args_arr);
void	ft_stack_creator(stack **head, int value);
void	ft_print_list(stack *head);
void	ft_swap_first_two(stack **head);

#endif