/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:46:22 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/19 17:16:39 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_length(t_stack *stack)
{
	int	i;

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

int	get_min_value(t_stack *stack)
{
	int	value;

	value = stack->value;
	while (stack)
	{
		if (value > stack->value)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}

int	get_max_value(t_stack *stack)
{
	int	value;

	value = stack->value;
	while (stack)
	{
		if (value < stack->value)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}

int	get_range(t_stack *stack)
{
	int	lowest;
	int	highest;
	int	range;

	lowest = get_min_value(stack);
	highest = get_max_value(stack);
	range = highest - lowest;
	return (range);
}

bool	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
