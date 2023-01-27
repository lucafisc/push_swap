/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:50:50 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/27 13:51:06 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	map_number(int length, char *argv[], int i)
{
	int	smaller;
	int	j;

	j = 1;
	smaller = 0;
	while (j <= length)
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[j]))
			smaller++;
		j++;
	}
	return (length - smaller);
}
