/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:04:23 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/31 15:39:41 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int rotate(t_stack *stack, int type_rotate)
{
    t_node  *tmp1;
    t_node  *tmp2;
    t_node  *tmp3;

    if (stack->size < 2)
        return (ERROR);
    tmp1 = stack->top;
    tmp2 = stack->top->next;
    tmp3 = stack->bot;
    stack->top = tmp2;
    stack->top->prev = NULL;
    stack->top->next = tmp2->next;
    stack->bot->prev = tmp3;
    tmp3->next = tmp1;
    stack->bot = tmp1;
    stack->bot->next = NULL;
    if (type_rotate == STACKA)
        ft_printf("ra\n");
    if (type_rotate == STACKB)
        ft_printf("rb\n");
    return (SUCCESS);
}

int doble_rotate(t_stack *a, t_stack *b)
{
    if (a->size < 2 || b->size < 2)
        return (ERROR);
    rotate (a, 0);
    rotate (b, 0);
    ft_printf("rr\n");
    return (SUCCESS);
}

