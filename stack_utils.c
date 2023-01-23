/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:46:22 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/23 18:06:23 by lde-ross         ###   ########.fr       */
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

sort_params	get_max_info(t_stack *stack)
{
	sort_params max;
	max.rotate = true;
	max.value = stack->value;
	int	middle;

	max.found = false;
	if (!stack)
	{
		max.value = 0;
		max.index = 0;
		return (max);
	}
	middle = get_stack_length(stack) / 2;
	while (stack)
	{
		if (max.value < stack->value)
		{
			max.value  = stack->value;
			max.index = stack->index;
			max.found = true;
		}
		stack = stack->next;
	}
	if (max.found && max.index > middle)
		max.rotate = false;
	return (max);
}

sort_params	get_min_info(t_stack *stack)
{
	sort_params min;
	min.rotate = true;
	min.value = stack->value;
	int	middle;

	min.found = false;
	middle = get_stack_length(stack) / 2;
	while (stack)
	{
		if (min.value > stack->value)
		{
			min.value  = stack->value;
			min.index = stack->index;
			min.found = true;
		}
		stack = stack->next;
	}
	if (min.found && min.index > middle)
		min.rotate = false;
	return (min);
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
