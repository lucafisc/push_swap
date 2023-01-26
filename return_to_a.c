/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross <lde-ross@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:11 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 09:44:02 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

sort_params get_optimal_move(t_stack *stack, int match)
{
	sort_params node;

	node.rotate = true;
	node.found = false;
	node.index = 0;

	while (stack)
	{
		if (stack->value == match)
		{
			node.found = true;
			node.index = stack->index;
			node.value = stack->value;
			if (node.index >= get_stack_middle(stack))
				node.rotate = false;
			return (node);
		}
		stack = stack->next;
	}
	return (node);
}

void return_to_a(t_stack **a, t_stack **b)
{
	t_stack *last;
	int max_in_b;
	sort_params instructions;
	int	bottom;

	bottom = 0;
	while (get_stack_length(*b) > 0)
	{
		max_in_b = get_max_value(*b);
		instructions = get_optimal_move(*b, max_in_b);
		last = stack_get_last(*a);
		if (last->value < (*a)->value && last->value > max_in_b)
		{
			bottom--;
			reverse_rotate(a, 'a');
		}
		else if ((*b)->value == max_in_b)
			push(b, a, 'a');
		else if (bottom == 0 || (*b)->value > last->value)
		{
			bottom++;
			push(b, a, 'a');
			rotate(a, 'a');
		}
		else
		{
			while ((*b)->value != max_in_b)
			{
				if (instructions.rotate)
					rotate(b, 'b');
				else
					reverse_rotate(b, 'b');
			}
			push(b, a, 'a');
		}
	}
}
