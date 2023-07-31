/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:29:36 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/31 12:17:00 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int swap(t_stack *stack, int type_swap)
{
    t_node  *tmp1;
    t_node  *tmp2;

    if (stack->size < 2) //REALMENTE NECESARIO SI EN TWO_SWAP ya PONGO LA CONDICION < 2 ERROR? 
        return (ERROR);
    tmp1 = stack->top;
    tmp2 = stack->top->next;
    stack->top = tmp2;
    tmp1->next = tmp2->next;
    stack->top->next = tmp1;
    stack->top->prev = NULL;
    tmp1->prev = stack->top;
    if (stack->size == 2)
        stack->bot = tmp1;
    if (stack->size > 2)
        stack->top->next->next->prev = tmp1;
    if (type_swap == STACKA)
        ft_printf("sa\n");
    if (type_swap == STACKB)
        ft_printf("sb\n");
    return (SUCCESS);
}

int doble_swap(t_stack *a, t_stack *b)
{
    if (a->size < 2 || b->size < 2) 
        return (ERROR);
    swap(a, 0);
    swap(b, 0);
    ft_printf("ss\n");
    return (SUCCESS);
}