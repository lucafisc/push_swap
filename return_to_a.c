/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:11 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 17:27:35 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

sort_params	find_move(t_stack *stack, int match)
{
	sort_params	node;

	node.rotate = true;
	node.index = 0;
	while (stack)
	{
		if (stack->value == match)
		{
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

void	move_max_to_a(t_stack **a, t_stack **b, sort_params instructions)
{
	while ((*b)->value != instructions.value)
	{
		if (instructions.rotate)
			rotate(b, 'b');
		else
			reverse_rotate(b, 'b');
	}
	push(b, a, 'a');
}

void	send_to_a(t_stack **a, t_stack **b, sort_params instructions, t_stack *last, int *bottom)
{
	if (last->value < (*a)->value && last->value > instructions.value)
	{
		*bottom = *bottom - 1;
		reverse_rotate(a, 'a');
	}
	else if ((*b)->value == instructions.value)
		push(b, a, 'a');
	else if (*bottom == 0 || (*b)->value > last->value)
	{
		*bottom = *bottom + 1;
		push(b, a, 'a');
		rotate(a, 'a');
	}
	else
		move_max_to_a(a, b, instructions);
}

void	return_to_a(t_stack **a, t_stack **b)
{
	t_stack		*last;
	sort_params	instructions;
	int			bottom;

	bottom = 0;
	while (get_stack_length(*b) > 0)
	{
		instructions = find_move(*b, get_max_value(*b));
		last = stack_get_last(*a);
		send_to_a(a, b, instructions, last, &bottom);
	}
	last = stack_get_last(*a);
	if (last->value < (*a)->value)
		reverse_rotate(a, 'a');
}
