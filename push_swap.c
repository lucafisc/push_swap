/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:41:06 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/19 17:18:03 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count = 0;

void	push_swap(int length, char *argv[])
{
	t_stack	*a;

	a = init_stack(length, argv);
	if (is_sorted(a))
		ft_printf("is sorted!\n");
	else if (length <= 3)
		sort_three(&a);
	else
		sort_big(&a, length);
	print_cmd(" ");
	clear_stack(&a);
}
