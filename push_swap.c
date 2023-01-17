/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:41:06 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/17 19:20:44 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list* find_smallest(t_list *lst)
// {
// 	t_list	*smallest;
// 	int	n;

// 	if (!lst)
// 		return (0);
// 	n = *(int*)lst->content;
// 	smallest = lst;
// 	while (lst)
// 	{
// 		if (*(int*)lst->content > n)
// 			{
// 				n = *(int*)lst->content;
// 				smallest = lst;
// 			}
// 		lst = lst->next;
// 	}
// 	return (smallest);

// }

int	get_range(t_stack *stack)
{
	int	lowest;
	int	highest;
	int	range;

	lowest = stack->value;
	highest = stack->value;
	while (stack)
	{
		if (lowest > stack->value)
			lowest = stack->value;
		if (highest < stack->value)
			highest = stack->value;
		stack = stack->next;
	}
	range = highest - lowest;
	return (range);
}

unsigned int	get_max_index(t_stack *stack)
{
		int				value;
		unsigned int	index;

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

unsigned int	get_min_index(t_stack *stack)
{
		int				value;
		unsigned int	index;

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

void sort_three(t_stack **stack)
{
	unsigned int	max_index;
	unsigned int	min_index;

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

	first.index = 0;
	while (stack)
	{
		if (stack->value <= key)
		{
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
	
	last.index = 0;
	while (stack)
	{
		if (stack->value <= key)
		{
			last.index = stack->index;
			last.value = stack->value;
		}
		stack = stack->next;
	}
	return (last);
}

sort_params	find_cheapest_move(t_stack *stack, int key)
{
	int	middle;
	sort_params first;
	sort_params last;

	first = find_info_first_match(stack, key);
	last = find_info_last_match(stack, key);
	middle = get_stack_middle(stack);
	if (middle - first.index > last.index - middle)
		return (first);
	else
		return (last);
}

void	sort_big(t_stack **a, int	length)
{
	t_stack	*b;
	int		range;
	int		key;
	int		ratio;
	int		middle;
	int		number_to_be_moved;
	sort_params	instructions;
	
	ratio = 25; //ratio defines the amount of chunks
	b = NULL;
	range = get_range(*a);
	key = range / (length / ratio);
	middle = get_stack_middle(*a);
	instructions = find_cheapest_move(*a, key);
	
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
