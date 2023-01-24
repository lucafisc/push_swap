/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:51:01 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/24 14:10:38 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

sort_params find_info_first_match(t_stack *stack, int key)
{
	sort_params first;

	first.rotate = true;
	first.found = false;
	first.index = 0;
	while ((int)stack->index <= get_stack_middle(stack))
	{
		if (stack->value < key)
		{
			first.found = true;
			first.index = stack->index;
			first.value = stack->value;
			return (first);
		}
		stack = stack->next;
	}
	return (first);
}

sort_params find_info_last_match(t_stack *stack, int key)
{
	sort_params last;

	last.rotate = false;
	last.found = false;
	last.index = 0;
	while ((int)stack->index < get_stack_middle(stack))
		stack = stack->next;
	while (stack)
	{
		if (stack->value < key)
		{
			last.index = stack->index;
			last.value = stack->value;
			last.found = true;
		}
		stack = stack->next;
	}
	return (last);
}

sort_params find_cheapest_move(t_stack *stack, int ceiling)
{
	int middle;
	sort_params first;
	sort_params last;

	first = find_info_first_match(stack, ceiling);
	last = find_info_last_match(stack, ceiling);
	middle = get_stack_middle(stack);
	// if (first.found)
	// 	//ft_printf("first found!\n");
	// if (last.found)
	// 	//ft_printf("last found!\n");
	if (middle - first.index > last.index - middle && first.found)
		return (first);
	else
		return (last);
}

void move_to_b(t_stack **a, t_stack **b, sort_params instructions)
{
	// sort_params	max_in_b;

	// max_in_b = get_max_info(*b);

	// ft_printf("\nmax in b: %d\n", max_in_b.value);
	while ((*a)->value != instructions.value)
	{
		if ((*a)->next->value == instructions.value)
		{
			swap(a, 'a');
			if ((*b) && (*b)->next && (*b)->value < (*b)->next->value)
				swap(b, 'b');
		}
		else if (instructions.rotate)
		{
			rotate(a, 'a');
			// if (max_in_b.found && (*b) && instructions.value > max_in_b.value && max_in_b.rotate && (*b)->value != max_in_b.value)
			// 	rotate(b, 'b');
		}
		else
		{
			reverse_rotate(a, 'a');
			// if (max_in_b.found && (*b) && instructions.value > max_in_b.value && !max_in_b.rotate && (*b)->value != max_in_b.value)
			// 	reverse_rotate(b, 'b');
		}
	}
	// if (max_in_b.found && (*b) && instructions.value > max_in_b.value)
	// {
	// 	while ((*b)->value != max_in_b.value)
	// 	{
	// 		if (max_in_b.rotate)
	// 			rotate(b, 'b');
	// 		else
	// 			reverse_rotate(b, 'b');
	// 	}
	// }
	push(a, b, 'b');
}

sort_params find_match(t_stack *stack, int match)
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

void move_back(t_stack **a, t_stack **b)
{
	int match;
	sort_params instructions;
	t_stack *last_of_a;
	int down;

	down = 0;
	while (get_stack_length(*b) > 1)
	{
		last_of_a = stack_get_last(*a);
		match = get_max_value(*b);
		if ((*b)->value != match && (down == 0 || (*b)->value > last_of_a->value))
		{
			push(b, a, 'a');
			rotate(a, 'a');
			down++;
		}
		else
		{
			instructions = find_match(*b, match);
			while ((*b)->value != instructions.value && instructions.found)
			{
				if (instructions.rotate)
					rotate(b, 'b');
				else
					reverse_rotate(b, 'b');
			}
			if (instructions.found)
				push(b, a, 'a');
			if ((*a)->value < last_of_a->value)
			{
				reverse_rotate(a, 'a');
				swap(a, 'a');
				down--;
			}
		}
	}
	push(b, a, 'a');
}

void sort_big(t_stack **a, int length)
{
	t_stack *b;
	int ceiling;
	int ratio;
	sort_params instructions;

	ratio = (length / 4);
	if (length < 10)
		ratio = 1;
	b = NULL;
	ceiling = get_min_value(*a) + ratio;

	instructions = find_cheapest_move(*a, ceiling);
	// ft_printf("value: %d index: %u ceiling: %d\n", instructions.value, instructions.index, ceiling);
	while (get_stack_length(*a) > 3)
	{
		while (instructions.found && get_stack_length(*a) > 3)
		{
			// ft_printf("value: %d index: %u ceiling: %d\n", instructions.value, instructions.index, ceiling);
			move_to_b(a, &b, instructions);
			// ft_printf("%d pushed to b!\n", instructions.value);
			// ft_printf("\n___________________________________\n\n\n", instructions.value);
			instructions = find_cheapest_move(*a, ceiling);
		}
		ceiling += ratio;
		if (ceiling > get_max_value(*a))
			ceiling = get_max_value(*a);
		instructions = find_cheapest_move(*a, ceiling);
	}
	sort_three(a);
	// print_stack_info(b);
	// print_stack_info(*a);
	move_back(a, &b);
	// print_stack_info(b);
	// print_stack_info(*a);
	clear_stack(&b);
}
