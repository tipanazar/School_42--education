
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct stack
{
	int value;
	struct stack *next;
} stack_a;

void	ft_print_test(void);

#endif