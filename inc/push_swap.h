/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:39:17 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/01 20:13:58 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../00_libft/libft.h"
# include "../00_libft/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

// ------------------ STRUCTURES -------------- //

# define ERROR 		-1
# define SUCCESS 	0
# define STACKA 	1
# define STACKB 	2
# define ASC 		1
# define DESC		2

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
}	t_stack;

void	stack_free(t_stack *stack);
void	doble_free(t_stack *a, t_stack *b);
int		init(t_stack **stack);
int		doble_init(t_stack **a, t_stack **b);
int		push_stack(t_stack *stack, int data, int index);
int		pop_stack(t_stack *stack);
int		push(t_stack *src, t_stack *dst, int type_push);
int		check_argumentos(int argc, char **argv);
int		check_argv(char **argv);
int		check_lim(int argc, char **argv);
int		check_duplicate(int argc, char **argv);
int		swap(t_stack *stack, int type_swap);
int		doble_swap(t_stack *a, t_stack *b);
int		rotate(t_stack *stack, int type_rotate);
int		doble_rotate(t_stack *a, t_stack *b);
int		reverse_rotate(t_stack *stack, int type_reverse);
int		doble_reverse_rotate(t_stack *a, t_stack *b);
int		setup_stack(int argc, char **argv, t_stack *stack);
void	indexer(t_stack *stack);
int		stack_sorted(t_stack *stack, int type);
int		stack_size(t_stack *a, t_stack *b);
int		size_three(t_stack *stack);
int		find_num(t_stack *stack, int ind);
int		size_four(t_stack *a, t_stack *b);
int		size_five(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
void	sort_digits(t_stack *a, t_stack *b, int bit);
void	print_stack(t_stack *stack);
#endif