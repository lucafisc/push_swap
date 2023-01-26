/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:33:56 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 16:50:14 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **a, t_stack **b, sort_params instructions, int limit)
{
	while ((*a)->value != instructions.value)
	{
		if (instructions.rotate)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
	if ((*b)->value < limit)
		rotate(b, 'b');
}

sort_params	get_first_match(t_stack *stack, int ceiling)
{
	sort_params	first;

	first.rotate = true;
	first.index = -1;
	while ((int)stack->index <= get_stack_middle(stack))
	{
		if (stack->value < ceiling)
		{
			first.index = stack->index;
			first.value = stack->value;
			return (first);
		}
		stack = stack->next;
	}
	return (first);
}

sort_params	get_last_match(t_stack *stack, int ceiling)
{
	sort_params	last;

	last.rotate = false;
	last.index = -1;
	while ((int)stack->index < get_stack_middle(stack))
		stack = stack->next;
	while (stack)
	{
		if (stack->value < ceiling)
		{
			last.index = stack->index;
			last.value = stack->value;
		}
		stack = stack->next;
	}
	return (last);
}

sort_params	get_optimal_move(t_stack *stack, int ceiling)
{
	int			middle;
	sort_params	first;
	sort_params	last;

	first = get_first_match(stack, ceiling);
	last = get_last_match(stack, ceiling);
	middle = get_stack_middle(stack);
	if (first.index >= 0 && middle - first.index > last.index - middle)
		return (first);
	else
		return (last);
}

int	cube(int x)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (i < 3)
	{
		result *= x;
		i++;
	}
	return (result);
}

int	get_ratio(int length)
{
	if (length < 10)
	{
		return (1);
	}
	else if (length < 100)
	{
		return ((length - 10) * 0.04 + 1);
	}
	else if (length < 500)
	{
		return ((length - 100) * 0.02 + 14);
	}
	else
	{
		return ((length - 500) * 0.006 + 30);
	}
}

void	fill_b(t_stack **a, t_stack **b, int length)
{
	int			ceiling;
	int			ratio;
	sort_params	instructions;

	ratio = get_ratio(length);
	ceiling = get_min_value(*a);
	while (get_stack_length(*a) > 3)
	{
		ceiling += (ratio * 2);
		if (ceiling > get_third_max_value(*a))
			ceiling = get_third_max_value(*a);
		instructions = get_optimal_move(*a, ceiling);
		while (instructions.index >= 0 && get_stack_length(*a) > 3)
		{
			send_to_b(a, b, instructions, ceiling - ratio);
			instructions = get_optimal_move(*a, ceiling);
		}
	}
}
