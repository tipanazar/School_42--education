#include "push_swap.h"


int	main(int argc, char *argv[])
{
	// ft_printf("%d, %s\n", argc, argv[0]);
	// ft_print_test();
	(void)argc;
	stack *stack_a = ft_create_stack(argv);
	printf("Value: %d\n",stack_a[0].value);
	return (0);
}
