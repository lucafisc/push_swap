/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:51:15 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 17:52:55 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_get_second_last(t_stack *stack)
{
	t_stack	*scnd_last;

	scnd_last = stack;
	while (scnd_last && scnd_last->next->next)
		scnd_last = scnd_last->next;
	return (scnd_last);
}

t_stack	*stack_get_last(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last && last->next)
		last = last->next;
	return (last);
}
