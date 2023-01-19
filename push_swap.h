/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-ross < lde-ross@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:59:58 by lde-ross          #+#    #+#             */
/*   Updated: 2023/01/19 16:48:38 by lde-ross         ###   ########.fr       */
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
	int				value;
	int	index;
	struct s_stack *next;
} t_stack;

typedef struct {
  int	value;
  int	index;
  bool	rotate;
  bool found;
} sort_params;

extern int count;

int		main(int argc, char *argv[]);
void	push_swap(int n, char *argv[]);
bool	is_valid_input(int argc, char *argv[]);
void	throw_error(void);

//stack utils
t_stack	*init_stack(int n, char *argv[]);
t_stack	*stack_get_last(t_stack *stack);
t_stack	*stack_get_second_last(t_stack *stack);
int		get_stack_length(t_stack *stack);
int		get_stack_middle(t_stack *stack);
void	stack_update_index(t_stack **stack);
void	clear_stack(t_stack **stack);
int get_min_value(t_stack *stack);
int get_max_value(t_stack *stack);
bool is_sorted(t_stack *stack);



//print command
void print_cmd(char *str);

//commands
void	push(t_stack **src, t_stack **dest, char x);
void	swap(t_stack **stack, char x);
void	rotate(t_stack **stack, char x);
void	reverse_rotate(t_stack **stack, char x);

void	sort_three(t_stack **stack);


#endif
