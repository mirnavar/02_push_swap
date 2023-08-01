/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:45:13 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/01 20:58:25 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	push_stack(t_stack *stack, int data, int index)
{
	t_node	*new;

	new = (t_node *)ft_calloc(sizeof(t_node), 1);
	if (!new)
		return (ERROR);
	new->data = data;
	new->index = index;
	new->prev = NULL;
	new->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bot = new;
	}
	else
	{
		new->next = stack->top;
		stack->top->prev = new;
		stack->top = new;
	}
	stack->size++;
	return (SUCCESS);
}

int	pop_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->top)
		return (ERROR);
	tmp = stack->top;
	stack->top = tmp->next;
	if (!stack->top)
		stack->bot = NULL;
	else
		stack->top->prev = NULL;
	free (tmp);
	stack->size--;
	return (SUCCESS);
}

int	push(t_stack *src, t_stack *dst, int type_push)
{
	t_node	*node;

	if (!src || !src->top)
		return (ERROR);
	node = src->top;
	push_stack(dst, node->data, node->index);
	pop_stack(src);
	if (type_push == STACKA)
		ft_printf("pa\n");
	else if (type_push == STACKB)
		ft_printf("pb\n");
	return (SUCCESS);
}
