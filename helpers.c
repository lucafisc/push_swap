/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:53:36 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/19 16:59:03 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_info(t_stack *stack)
{
	ft_printf("\n-*-*-*-*-*-*-*-*-*-*-*-\nprinting stack info:\n-*-*-*-*-*-*-*-*-*-*-*-\n", stack->index, stack->value);
	while (stack)
	{
		ft_printf("[%d]: %d\n", stack->index, stack->value);
		stack = stack->next;
	}
	ft_printf("-*-*-*-*-*-*-*-*-*-*-*-\n");
}