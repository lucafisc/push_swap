/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:29:40 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/26 18:06:34 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (ft_is_sign(str[i]))
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

t_bool	is_duplicated(int *array, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (array[i] == c)
			return (true);
		i++;
	}
	return (false);
}

t_bool	is_valid_integer(int n, char *argv[])
{
	int			*array;
	int			i;
	long int	x;
	t_bool		is_valid;

	is_valid = true;
	array = (int *)malloc(sizeof(int) * n);
	if (!array)
		return (false);
	i = 0;
	while (i < n)
	{
		x = ft_atoli(argv[i + 1]);
		if (x > INT_MAX || x < INT_MIN)
			is_valid = false;
		array[i] = x;
		if (is_duplicated(array, array[i], i))
			is_valid = false;
		i++;
	}
	free(array);
	return (is_valid);
}

t_bool	is_valid_input(int n, char *argv[])
{
	int	i;

	i = 1;
	while (i <= n)
	{
		if (!is_valid_number(argv[i]))
			return (false);
		i++;
	}
	if (!is_valid_integer(n, argv))
		return (false);
	return (true);
}
