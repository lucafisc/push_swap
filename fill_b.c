/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:33:56 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 18:10:57 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_stack **a, t_stack **b, t_sort_params instruct, int limit)
{
	while ((*a)->value != instruct.value)
	{
		if (instruct.rotate)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
	if ((*b)->value < limit)
		rotate(b, 'b');
}

t_sort_params	get_first_match(t_stack *stack, int ceiling)
{
	t_sort_params	first;

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

t_sort_params	get_last_match(t_stack *stack, int ceiling)
{
	t_sort_params	last;

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

t_sort_params	get_optimal_move(t_stack *stack, int ceiling)
{
	int				middle;
	t_sort_params	first;
	t_sort_params	last;

	first = get_first_match(stack, ceiling);
	last = get_last_match(stack, ceiling);
	middle = get_stack_middle(stack);
	if (first.index >= 0 && middle - first.index > last.index - middle)
		return (first);
	else
		return (last);
}

void	fill_b(t_stack **a, t_stack **b, int length)
{
	int				ceiling;
	int				ratio;
	t_sort_params	instructions;

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
