#include "push_swap.h"

// t_list* find_smallest(t_list *lst)
// {
// 	t_list	*smallest;
// 	int	n;

// 	if (!lst)
// 		return (0);
// 	n = *(int*)lst->content;
// 	smallest = lst;
// 	while (lst)
// 	{
// 		if (*(int*)lst->content > n)
// 			{
// 				n = *(int*)lst->content;
// 				smallest = lst;
// 			}
// 		lst = lst->next;
// 	}
// 	return (smallest);

// }

int	get_range(t_stack *stack)
{
	int	lowest;
	int	highest;
	int	range;

	lowest = stack->value;
	highest = stack->value;
	while (stack)
	{
		if (lowest > stack->value)
			lowest = stack->value;
		if (highest < stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	range = highest - lowest;
	return (range);
}

// void sort_three(length, a)
// {

// }

bool is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	push_swap(int length, char *argv[])
{
	t_stack	*a;
	a = init_stack(length, argv);
	if (is_sorted(a))
		ft_printf("is sorted!");
	else if (length <= 3)
	{
		ft_printf("sort_small");
		//sort_three(length, a);
	}
	else
	{
		ft_printf("sort_big");
		//sort_big(length, a);
	}
}