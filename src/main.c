/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:25:49 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/20 16:40:12 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_stack(t_stack *stack)
{
    t_node *tmp;

    tmp = stack->top;
    while (tmp)
    {
        ft_printf("the data %d\nthe index %d\n", tmp->data, tmp->index);
        tmp = tmp->next;
    }
}

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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    if (!check_argumentos(argc, argv))
        ft_printf("Muy bien mireita\n");
    doble_init(&a, &b);
    int i = 8;
    int j = 1;
    while (i <= 10)
        push_stack(a, i++, j++);
    write(2, "stacka1\n", 8);
    print_stack(a);
    //pop_stack(a);
    push(a, b, STACKB);
    write(2, "stacka2\n", 8);
    print_stack(a);
    write(2, "stackb\n", 7);
    print_stack(b);
    swap(a, STACKA);
    print_stack(a);
    //print_stack(a->top->next);
    doble_free(a, b);
    return (SUCCESS);
}
