
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int value;
	struct s_stack *next;
} stack;

void	ft_print_test(void);
stack	*ft_create_stack(char **content);


#endif