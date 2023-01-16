/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:42 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/16 18:55:55 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// has to print last move indenpendently and free all the allcated memory.

void print_pairs(char **array)
{
	if (is_ss(array))
		ft_printf("ss\n");
	else if (is_rr(array))
		ft_printf("rr\n");
	else if (is_rrr(array))
		ft_printf("rrr\n");
}

void print_next_cmd(char **array)
{
	ft_printf("%s\n", array[1]);
	array[1] = ft_memcpy(array[1], array[0], 3);
	free(array[0]);
}

char **init_array()
{
	char **array;

	array = malloc(sizeof(char *) * 2);
	if (!array)
		return (NULL);
	return (array);
}

void	free_double_pointer(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if(array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

void print_cmd(char *str, bool is_last)
{
	static char **array;

	if (!array)
		array = init_array();
	if (!array[0][0])
	{
		array[0] = ft_calloc(sizeof(char), 4);
		array[0] = ft_memcpy(array[0], str, 3);
	}
	else if (!array[1][0])
	{
		array[1] = ft_calloc(sizeof(char), 4);
		array[1] = ft_memcpy(array[1], array[0], 3);
		free(array[0]);
		array[0] = ft_calloc(sizeof(char), 4);
		array[0] = ft_memcpy(array[0], str, 3);
	}
	if (are_pairs(array))
	{
		print_pairs(array);
		free_double_pointer(array, 2);
	}
	else if (array[0][0] && array[1][0])
		print_next_cmd(array);
	if (is_last)
	{
		if (array[1][0])
			ft_printf("%s\n", array[1]);
		free_double_pointer(array, 2);
	}
}
