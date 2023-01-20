/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:51:01 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/20 18:53:01 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

sort_params	find_info_first_match(t_stack *stack, int key)
{
	sort_params	first;

	first.rotate = true;
	first.found = false;
	first.index = 0;
	while ((int)stack->index <= get_stack_middle(stack))
	{
		if (stack->value <= key)
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

sort_params	find_info_last_match(t_stack *stack, int key)
{
	sort_params	last;

	last.rotate = false;
	last.found = false;
	last.index = 0;
	while ((int)stack->index < get_stack_middle(stack))
		stack = stack->next;
	while (stack)
	{
		if (stack->value <= key)
		{
			last.index = stack->index;
			last.value = stack->value;
			last.found = true;
		}
		stack = stack->next;
	}
	return (last);
}

sort_params	find_cheapest_move(t_stack *stack, int ceiling)
{
	int			middle;
	sort_params	first;
	sort_params	last;

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

void	move_to_b(t_stack **a, t_stack **b, sort_params instructions)
{
	//check cheapest way to rotate b to get the new number before pushing
	// t_stack	*last;
	// last = stack_get_last(*b);
	while ((*a)->value != instructions.value)
	{
		if (instructions.rotate)
			rotate(a, 'a');
		else
			reverse_rotate(a, 'a');
	}
//	ft_printf("%d is now on top of stack A\n", (*a)->value);
	
	push(a, b, 'b');
	// if ((*b)->next && (*b)->value < (*b)->next->value)
	// {
	// 	swap(b, 'b');
	// }

}

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


void	move_back(t_stack **a, t_stack **b)
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
	printf("pa\n");
	//push(b, a, 'a');
}

void	sort_big(t_stack **a, int length)
{
	t_stack		*b;
	int			ceiling;
	int			ratio;
	int	max;
	int	min;
	int middle;
	sort_params	instructions;

	min = get_min_value(*a);
	max = get_max_value(*a);
	middle = (min + max) / 2;
	ratio = (length / (middle / 6));
	b = NULL;
	ceiling = get_min_value(*a) + ratio;
	instructions = find_cheapest_move(*a, ceiling);
	//ft_printf("value: %d index: %u ceiling: %d\n", instructions.value, instructions.index, ceiling);
	while (get_stack_length(*a) > 3)
	{
		while (instructions.found && get_stack_length(*a) > 3)
		{
			//ft_printf("value: %d index: %u ceiling: %d\n", instructions.value, instructions.index, ceiling);
			move_to_b(a, &b, instructions);
			//ft_printf("%d pushed to b!\n", instructions.value);
			//ft_printf("\n___________________________________\n\n\n", instructions.value);
			instructions = find_cheapest_move(*a, ceiling);
		}
		ceiling += ratio;
		if (ceiling > get_max_value(*a))
			ceiling = get_max_value(*a);
		instructions = find_cheapest_move(*a, ceiling);
	}
	sort_three(a);
	print_stack_info(b);
	print_stack_info(*a);
	move_back(a, &b);
	print_stack_info(b);
	print_stack_info(*a);
	clear_stack(&b);
}
