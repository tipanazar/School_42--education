#include "push_swap.h"

// stack	*ft_create_stack(char **content)
// {
// 	stack	*first_node;
// 	stack	*current;
// 	stack	*next_list;
// 	int		idx;

// 	idx = 1;
// 	first_node = (stack *)malloc(sizeof(*first_node));
// 	if (!first_node)
// 		return (NULL);
// 	first_node->value = ft_atoi(content[idx]);
// 	first_node->next = NULL;
// 	while (content[++idx])
// 	{
// 		current = (stack *)malloc(sizeof(stack));
// 		if (!current)
// 			return (NULL);
// 		current->value = ft_atoi(content[idx]);
// 		current->next = NULL;
// 		if (!first_node->next)
// 			first_node->next = current;

// 	}
// 	return (first_node);
// }

stack	*ft_create_stack(char **content)
{
	stack	*new_node;
	int		idx;

	idx = 0;
	while (content[++idx])
	{
		new_node = (stack *)malloc(sizeof(stack));
		if (!new_node)
			return (NULL);
		new_node->value = ft_atoi(content[idx]);
		new_node->next = NULL;
		if (content[idx + 1])
			new_node = new_node->next;
	}
	return (new_node);
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