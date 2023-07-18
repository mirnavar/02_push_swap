/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:39:17 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/18 17:56:43 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../00_libft/libft.h"
# include "../00_libft/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

// ------------------ STRUCTURES -------------- //

#define ERROR -1
#define SUCCESS 0
#define STACKA 1
#define STACKB 2
typedef struct s_node
{
    int             data;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

typedef struct s_stack
{
    int     size;
    t_node  *top;
    t_node  *bot;
} t_stack;

void stack_free(t_stack *stack);
void doble_free(t_stack *a, t_stack *b);
int init(t_stack **stack);
int doble_init(t_stack **a, t_stack **b);
int push_stack(t_stack *stack, int data, int index);
int pop_stack(t_stack *stack);
int push(t_stack *src, t_stack *dst, int type_push);
#endif
