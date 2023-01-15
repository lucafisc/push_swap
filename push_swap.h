/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:58 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/15 18:36:55 by lde-ross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

typedef enum { false, true } bool;
typedef struct s_stack
{
	int value;
	int index;
	struct s_stack *next;
} t_stack;

//int		main(int argc, char *argv[]);
void	push_swap(int n, char *argv[]);
bool	is_valid_input(int argc, char *argv[]);
void	throw_error(void);
t_stack	*init_stack(int n, char *argv[]);
int		get_stack_length(t_stack *stack);
int		get_stack_middle(t_stack *stack);

//command compare
bool	is_ss(char **array);
bool	is_rr(char **array);
bool	is_rrr(char **array);
bool	are_pairs(char **array);



#endif
