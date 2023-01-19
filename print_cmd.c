/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:42 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/19 11:44:47 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool is_ss(char *str1, char *str2)
{
	if ((!ft_strncmp(str1, "sa", 2) && !ft_strncmp(str2, "sb", 2)) || (!ft_strncmp(str1, "sb", 2) && !ft_strncmp(str2, "sa", 2)))
		return (true);
	return (false);
}

bool is_rr(char *str1, char *str2)
{
	if ((!ft_strncmp(str1, "ra", 2) && !ft_strncmp(str2, "rb", 2)) || (!ft_strncmp(str1, "rb", 2) && !ft_strncmp(str2, "ra", 2)))
		return (true);
	return (false);
}

bool is_rrr(char *str1, char *str2)
{
	if ((!ft_strncmp(str1, "rra", 3) && !ft_strncmp(str2, "rrb", 3)) || (!ft_strncmp(str1, "rrb", 3) && !ft_strncmp(str2, "rra", 3)))
		return (true);
	return (false);
}

bool are_pairs(char *str1, char *str2)
{
	if (is_ss(str1, str2) || is_rr(str1, str2) || is_rrr(str1, str2))
		return (true);
	return (false);
}

void print_pairs(char *str1, char *str2)
{
	if (is_ss(str1, str2))
		ft_printf("ss\n");
	else if (is_rr(str1, str2))
		ft_printf("rr\n");
	else if (is_rrr(str1, str2))
		ft_printf("rrr\n");
}

void print_cmd(char *str)
{
	static char *cmd;

	count++;
	if (ft_strchr(str, ' ') && cmd)
	{
		ft_printf("%s\n", cmd);
		free(cmd);
	}
	else if (!cmd)
	{
		cmd = ft_strdup(str);
		ft_printf("\n\nallocating space for %s\n\n", cmd);
	}
	else if (are_pairs(cmd, str))
	{
		ft_printf("\nare pairs!!!\n");
		print_pairs(cmd, str);
		ft_printf("\nfreeing memory from %s!!!\n", cmd);
		// is throwing an error as double free
		free(cmd);
		cmd = NULL;
	}
	else
	{
		ft_printf("%s\n", cmd);
		free(cmd);
		cmd = ft_strdup(str);
		ft_printf("\n\nallocating space for %s\n\n", cmd);
	}
}
