#include "push_swap.h"

t_stack	*new_stack(int value)
{
	t_stack *stack;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

t_stack	*stack_get_last(t_stack *stack)
{
	t_stack *last;

	last = stack;
	while (last && last->next)
		last = last->next;
	return (last);
}

void	stack_add_back(t_stack *stack, t_stack *new_node)
{
	t_stack *last;

	last = stack_get_last(stack);
	last->next = new_node;
}

int	get_stack_length(t_stack *stack)
{
	int i;
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_stack_middle(t_stack *stack)
{
	return (get_stack_length(stack) / 2);
}

t_stack *init_stack(int n, char *argv[])
{
	t_stack	*stack;
	int		i;
	int		number;

	i = 1;
	while (i <= n)
	{
		number = ft_atoi(argv[i]);
		if (i == 1)
			stack = new_stack(number);
		else
			stack_add_back(stack, new_stack(number));
		i++;
	}
	return (stack);
}
