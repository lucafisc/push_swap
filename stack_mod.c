/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:29:01 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/27 13:51:03 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int value, int index)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = value;
	stack->index = index;
	stack->next = NULL;
	return (stack);
}

void	stack_update_index(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	stack_add_back(t_stack *stack, t_stack *new_node)
{
	t_stack	*last;

	last = stack_get_last(stack);
	last->next = new_node;
}

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_stack	*init_stack(int length, char *argv[])
{
	t_stack	*stack;
	int		i;
	int		number;

	i = 1;
	while (i <= length)
	{
		number = map_number(length, argv, i);
		if (i == 1)
			stack = new_stack(number, i - 1);
		else
			stack_add_back(stack, new_stack(number, i - 1));
		i++;
	}
	return (stack);
}
