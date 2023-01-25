/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:29:29 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/25 18:45:07 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
