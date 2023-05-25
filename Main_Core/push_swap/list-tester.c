#include "push_swap.h"

stack	*ft_create_stack(char **content)
{
	stack	*new_list;
	stack	*current;
	int		idx;

	while (content[++idx])
	{
		idx = 0;
		new_list = (stack *)malloc(sizeof(stack));
		if (!new_list)
			return (NULL);
		new_list->value = ft_atoi(content[idx]);
		new_list->next = NULL;
		if(current)
			current->next = new_list;
		current = new_list;

	}
	return (new_list);
}

// void	ft_list_tester(int *nums)
// {
// 	stack_a *current;
// 	stack_a *next;
// 	int idx = 1;
// 	while (nums[idx])
// 	{
// 	}
// }