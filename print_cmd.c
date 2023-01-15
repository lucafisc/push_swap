/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:39:42 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/15 16:55:24 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	print_pairs(char **array)
{
	if (is_ss(array))
		ft_printf("ss\n");
	else if (is_rr(array))
		ft_printf("rr\n");
	else if (is_rrr(array))
		ft_printf("rrr\n");
	free(array[0]);
	free(array[1]);
	free(array);
	array = NULL;
}

void	print_next_cmd(char **array)
{
		ft_printf("%s\n", array[1]);
		array[1] = t_memcpy(array[1], array[0], 2);
		ft_bzero(array[0], 3);
}

int    print_cmd(char *str)
{
    static char    **array;

    if (!array)  
       {
        array = malloc(sizeof(char *) * 2);
        array[0] = calloc(sizeof(char), 3);
        array[1] = calloc(sizeof(char), 3);
       }
    if (!array)
        return (0);
    if (!array[0][0])
        array[0] = t_memcpy(array[0], str, 2);
    else if (!array[1][0])
	{
		array[1] = t_memcpy(array[1], array[0], 2);
		array[0] = t_memcpy(array[0], str, 2);
	}
 	if (are_pairs(array))
		print_pairs(array);
	else if (array[0][0] && array [1][0])
		print_next_cmd(array);
    return (1);
}

int	main(void)
{
    print_cmd("sa");
    print_cmd("sb");
  	 print_cmd("rb");
      print_cmd("ra");
	      print_cmd("sa");

	return (0);
}