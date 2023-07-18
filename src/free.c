/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:03:00 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/18 17:47:16 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	stack_free(t_stack *stack)
{
	t_node	*temp;

	while (stack->top != NULL)
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free (temp);
	}
	free (stack);
}

void	doble_free(t_stack *a, t_stack *b)
{
	stack_free(a);
	stack_free(b);
}
