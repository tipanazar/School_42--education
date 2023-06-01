
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int value;
	struct s_stack *next;
} stack;

void	ft_create_stack(stack **head, int argc, char **args_arr);
void	ft_print_list(stack *head);
void	ft_swap_first_two(stack **head);
void	ft_checker(int argc, char **argv);
void	ft_free_list(stack *list);

#endif