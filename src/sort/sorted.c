/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:47:13 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/02 10:22:56 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_sorted(t_stack *stack, int type)
{
	t_node	*node;

	if (type == ASC)
	{
		node = stack->top;
		while (node && node->next)
		{
			if (node->data > node->next->data)
				return (0);
			node = node->next;
		}
	}
	if (type == DESC)
	{
		node = stack->bot;
		while (node && node->prev)
		{
			if (node->data < node->prev->data)
				return (0);
			node = node->prev;
		}
	}
	return (1);
}

int	stack_size_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		swap(a, STACKA);
		return (SUCCESS);
	}
	if (a->size == 3)
	{
		size_three(a);
		return (SUCCESS);
	}
	if (a->size == 4)
	{
		size_four(a, b);
		return (SUCCESS);
	}
	if (a->size == 5)
	{
		size_five(a, b);
		return (SUCCESS);
	}
	return (0);
}

int	stack_size_big(t_stack *a, t_stack *b)
{
	if (a->size > 5)
	{
		sort_big(a, b);
		return (SUCCESS);
	}
	return (0);
}
