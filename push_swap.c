/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:41:06 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/19 16:22:26 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count = 0;

int get_max_index(t_stack *stack)
{
	int value;
	int index;

	value = stack->value;
	index = stack->index;
	while (stack)
	{
		if (value < stack->value)
		{
			value = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

int get_min_index(t_stack *stack)
{
	int value;
	int index;

	value = stack->value;
	index = stack->index;
	while (stack)
	{
		if (value > stack->value)
		{
			value = stack->value;
			index = stack->index;
		}
		stack = stack->next;
	}
	return (index);
}

int get_min_value(t_stack *stack)
{
	int value;

	value = stack->value;
	while (stack)
	{
		if (value > stack->value)
			value = stack->value;
		stack = stack->next;
	}
	return (value);
}

int get_max_value(t_stack *stack)
{
	int value;

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
	highest = get_max_index(stack);
	range = highest - lowest;
	return (range);
}

void sort_three(t_stack **stack)
{
	int	max_index;
	int	min_index;

	max_index = get_max_index(*stack);
	min_index = get_min_index(*stack);
	if (max_index == 2 && min_index == 1)
		swap(stack, 'a');
	else if (max_index == 0 && min_index == 1)
		rotate(stack, 'a');
	else if (max_index == 1 && min_index == 2)
		reverse_rotate(stack, 'a');
	else if (max_index == 1 && min_index == 0)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (max_index == 0 && min_index == 2)
	{
		swap(stack, 'a');
		reverse_rotate(stack, 'a');
	}
}

bool is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_five(t_stack **a)
{
	t_stack	*b;
	b = NULL;
	push(a, &b, 'b');
	push(a, &b, 'b');
	sort_three(a);
	ft_printf("value of first a: %d\n", (*a)->value);
	while (b->value > (*a)->value)
		rotate(a, 'a');
	push(&b, a, 'a');
	while (b->value > (*a)->value)
		rotate(a, 'a');
	push(&b, a, 'a');
	
	clear_stack(&b);
}

sort_params	find_info_first_match(t_stack *stack, int key)
{
	sort_params first;
	first.rotate = true;
	first.found = false;

	first.index = 0;
	ft_printf("this is the stack middle %d\n",get_stack_middle(stack));
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
	int	middle;
	sort_params first;
	sort_params last;

	first = find_info_first_match(stack, ceiling);
	last = find_info_last_match(stack, ceiling);
	middle = get_stack_middle(stack);
	//ft_printf("middle(%d) - first.index(%d) = (%d) > last.index(%d) - middle(%d) = (%d) ?\n",middle, first.index, middle - first.index, last.index, middle, last.index - middle);
	if (first.found)
		ft_printf("first found!\n");
	if (last.found)
		ft_printf("last found!\n");
	if (middle - first.index > last.index - middle && first.found)
	{
		//ft_printf("returning first: value: %d index: %u\n", first.value, first.index);
		return (first);
	}
	else
	{
		//ft_printf("returning last: value: %d index: %u\n", last.value, last.index);
		return (last);
	}
}

void	move_to_b(t_stack **a, t_stack **b, sort_params instructions)
{
	//check cheapest way to rotate b to get the new number before pushing
	// t_stack	*last;

	// last = stack_get_last(*b);
	
	while ((*a)->value != instructions.value)
	{
		if (instructions.rotate)
		{
			// optimisation?? protect if be was not initialized

			// if (b && *b && (*b)->next && (*a)->next->value == instructions.value && (*b)->value < (*b)->next->value)
			// {
			// 	swap(a, 'a');
			// 	swap(b, 'b');
			// }
			// else
			rotate(a, 'a');
			// if ((*b)->next && (*b)->next->next && (*b)->value > instructions.value)
			// 	rotate(b, 'b');
				// if ((*b)->value < instructions.value)
				// {
				// 	ft_printf("\n\n\nwill rotate and send %d to the last index to put %d on top\n\n\n", (*b)->value, instructions.value);
				// 	rotate(b, 'b');
				// }
			
		}
		else
			reverse_rotate(a, 'a');
	}
	ft_printf("%d is now on top of stack A\n", (*a)->value);
	// if ((*b)->next && (*b)->next->next)
	// {
	// 	while ((*b)->value > instructions.value)
	// 	{
	// 		rotate(b, 'b');
	// 	}
		
		
	// }
	push(a, b, 'b');
	if ((*b)->next && !(*b)->next->next && (*b)->value < (*b)->next->value)
		swap(b, 'b');
}


void	sort_big(t_stack **a, int length)
{
	t_stack	*b;
	t_stack *temp;
	// int		range;
	int		ceiling;
	int		ratio;
	sort_params	instructions;
	
	// range = get_range(*a);
	ratio = (length / 6); //ratio defines the amount of chunks
	b = NULL;
	ceiling = get_min_value(*a) + ratio;
	instructions = find_cheapest_move(*a, ceiling);
	ft_printf("value: %d index: %u ceiling: %d\n", instructions.value, instructions.index, ceiling);
	while (get_stack_length(*a) > 3)
	{
		while (instructions.found && get_stack_length(*a) > 3)
		{
			ft_printf("value: %d index: %u ceiling: %d\n", instructions.value, instructions.index, ceiling);
			move_to_b(a, &b, instructions);
			ft_printf("%d pushed to b!\n", instructions.value);
			ft_printf("\n___________________________________\n\n\n", instructions.value);
			instructions = find_cheapest_move(*a, ceiling);
		}
		ceiling += ratio;
		if (ceiling > get_max_value(*a))
			ceiling = get_max_value(*a);
		instructions = find_cheapest_move(*a, ceiling);
	}
	sort_three(a);


	// ft_printf("ceiling: %d\n", ceiling);
	// ft_printf("index: %u, value: %d\n", instructions.index, instructions.value);
	// ft_printf("value of b index 0: %d\n", b->value);
	// ft_printf("value of a index 0: %d\n", (*a)->value);
	temp = b;
	while (temp)
	{
		ft_printf("index: %d, value: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
		clear_stack(&b);

}

void	push_swap(int length, char *argv[])
{
	t_stack	*a;
	// t_stack	*last;
	a = init_stack(length, argv);
	if (is_sorted(a))
		ft_printf("is sorted!\n");
	else if (length <= 3)
	{
		ft_printf("sort_small\n");
		sort_three(&a);
	}
	else if (length <= 5)
	{
		sort_five(&a);
	}
	else
	{
		ft_printf("sort_big\n");
		// rotate(&a, 'a');
		// ft_printf("value of first: %d\n", a->value);
		// ft_printf("index of first: %d\n", a->index);
		// ft_printf("value of second: %d\n", a->next->value);
		// ft_printf("index of second: %d\n", a->next->index);
		// last = stack_get_last(a);
		// ft_printf("value of last: %d\n", last->value);
		// ft_printf("index of last: %d\n", last->index);
		sort_big(&a, length);
	}
	print_cmd(" ");
	clear_stack(&a);
}
