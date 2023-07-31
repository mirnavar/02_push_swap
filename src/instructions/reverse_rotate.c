/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:32:42 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/31 16:35:57 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int reverse_rotate(t_stack *stack, int type_reverse)
{
    t_node  *tmp1;
    t_node  *tmp2;
    t_node  *tmp3;

    if (stack->size < 2)
        return (ERROR);
    tmp1 = stack->top;
    tmp2 = stack->bot->prev;
    tmp3 = stack->bot;
    stack->top = tmp3;
    stack->top->prev = NULL;
    stack->top->next = tmp1;
    //tmp3->next = tmp1;
    stack->bot = tmp2;
    stack->bot->next = NULL;
    //stack->bot->prev = tmp2->prev;
    if (type_reverse == STACKA)
        ft_printf("rra\n");
    if (type_reverse == STACKB)
        ft_printf("rrb\n");
    return(SUCCESS);
}

int	doble_reverse_rotate(t_stack *a, t_stack *b)
{
	if (a->size < 2 || b->size < 2)
		return (ERROR);
	reverse_rotate (a, 0);
	reverse_rotate (b, 0);
	ft_printf("rrr\n");
	return (SUCCESS);
}