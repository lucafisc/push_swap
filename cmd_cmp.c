/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:41 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/15 18:43:22 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_ss(char **array)
{
	if ((!ft_strncmp(array[0], "sa", 2) && !ft_strncmp(array[1], "sb", 2))
	|| (!ft_strncmp(array[0], "sb", 2) && !ft_strncmp(array[1], "sa", 2)))
		return (true);
	return (false);
}

bool	is_rr(char **array)
{
	if ((!ft_strncmp(array[0], "ra", 2) && !ft_strncmp(array[1], "rb", 2))
	|| (!ft_strncmp(array[0], "rb", 2) && !ft_strncmp(array[1], "ra", 2)))
		return (true);
	return (false);
}

bool	is_rrr(char **array)
{
	if ((!ft_strncmp(array[0], "rra", 3) && !ft_strncmp(array[1], "rrb", 3))
	|| (!ft_strncmp(array[0], "rrb", 3) && !ft_strncmp(array[1], "rra", 3)))
		return (true);
	return (false);
}

bool	are_pairs(char **array)
{
	if (is_ss(array) || is_rr(array) || is_rrr(array))
		return (true);
	return (false);
}
