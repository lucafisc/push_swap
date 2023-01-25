/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:51:01 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/25 18:41:55 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack **a, int length)
{
	t_stack		*b;

	b = NULL;
	fill_b(a, &b, length);
	sort_three(a);
	return_to_a(a, &b);
	clear_stack(&b);
}
