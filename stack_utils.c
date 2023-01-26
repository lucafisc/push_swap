/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:46:22 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 17:48:48 by lde-ross         ###   ########.fr       */
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

int	get_third_max_value(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = INT_MIN;
	second = INT_MIN;
	third = INT_MIN;
	while (stack)
	{
		if (stack->value > first)
		{
			third = second;
			second = first;
			first = stack->value;
		}
		else if (stack->value > second)
		{
			third = second;
			second = stack->value;
		}
		else if (stack->value > third)
			third = stack->value;
		stack = stack->next;
	}
	return (third);
}
