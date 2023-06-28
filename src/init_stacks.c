/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:16:11 by mirnavar          #+#    #+#             */
/*   Updated: 2023/06/28 12:46:34 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	double_init(t_stack **A, t_stack **B)
{
	if (stack_init(A) == 0 || stack_init(B) == 0)
		ft_error(0);
	return(1);
}

static int	stack_init(t_stack **stack)
{
	*stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return(0);
	(*stack)->size = 0;
	(*stack)->top = NULL;
	(*stack)->bott = NULL;
	return(1);
}
