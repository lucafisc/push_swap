/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:29:29 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 16:32:03 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	throw_error(void)
{
	ft_printf("Error");
}

void	push_swap(int length, char *argv[])
{
	t_stack	*a;

	a = init_stack(length, argv);
	if (is_sorted(a))
	{
		clear_stack(&a);
		return ;
	}
	else if (length <= 3)
		sort_three(&a);
	else
		sort_big(&a, length);
	print_cmd(" ");
	clear_stack(&a);
}

int	main(int argc, char *argv[])
{
	if (argc <= 1)
		return (0);
	else if (is_valid_input(argc - 1, argv))
		push_swap(argc - 1, argv);
	else
		throw_error();
	return (0);
}
