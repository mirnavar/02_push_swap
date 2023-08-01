/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:47:13 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/01 12:47:48 by mirnavar         ###   ########.fr       */
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