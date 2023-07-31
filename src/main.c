/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:25:49 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/31 11:56:24 by mirnavar         ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    if (!check_argumentos(argc, argv))
        ft_printf("Muy bien mireita\n");
    doble_init(&a, &b);
    int i = 8;
    int j = 1;
    while (i <= 12)
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
    push(a, b, STACKB);
    swap(b, STACKB);
    print_stack(b);
    //print_stack(a->top->next);
    doble_free(a, b);
    return (SUCCESS);
}
