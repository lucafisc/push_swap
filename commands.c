/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:28:46 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/16 17:18:34 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char x)
{
	t_stack	*second;

	second = (*stack)->next;
	(*stack)->index = 1;
	(*stack)->next = second->next;
	second->next = *stack;
	second->index = 0;
	if (x == 'a')
		print_cmd("sa");
	else
		print_cmd("sb");
}

void	rotate(t_stack **stack, char x)
{
	t_stack	*last;
	t_stack	*temp;

	temp = *stack;
	last = stack_get_last(*stack);
	last->next = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	temp = *stack;
	while (temp->next)
	{
		temp->index -= 1;
		temp = temp->next;
	}
	temp->index = get_stack_length(*stack) - 1;
	if (x == 'a')
		print_cmd("ra");
	else
		print_cmd("rb");
}

void	reverse_rotate(t_stack **stack, char x)
{	
	t_stack	*last;
	t_stack *scnd_last;
	t_stack	*temp;

	last = stack_get_last(*stack);
	scnd_last = stack_get_second_last(*stack);
	scnd_last->next = NULL;
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	(*stack)->index = 0;
	while (temp)
	{
		temp->index += 1;
		temp = temp->next;
	}
	if (x == 'a')
		print_cmd("rra");
	else
		print_cmd("rrb");
}
