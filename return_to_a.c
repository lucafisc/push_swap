/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:37:11 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/25 18:55:42 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

sort_params	find_match(t_stack *stack, int match)
{
	sort_params	node;

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

void	return_to_a(t_stack **a, t_stack **b)
{
	int	match;
	sort_params	instructions;

	match = get_max_value(*b);
	while (get_stack_length(*b) > 1)
	{
		instructions = find_match(*b, match);
		while ((*b)->value != instructions.value && instructions.found)
		{
			if (instructions.rotate)
				rotate(b, 'b');
			else
				reverse_rotate(b, 'b');
			//ft_printf("MATCH!: index: %d value: %d searched for: %d\n", instructions.index, instructions.value, match);
		}
		if (instructions.found)
			push(b, a, 'a');
			
		match--;
		
	}
	push(b, a, 'a');
}