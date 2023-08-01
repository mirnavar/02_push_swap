/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:01:06 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/31 17:51:03 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	init(t_stack **stack)
{
	*stack = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!stack)
		return (ERROR);
	(*stack)->size = 0;
	(*stack)->top = NULL;
	(*stack)->bot = NULL;
	return (SUCCESS);
}

int	doble_init(t_stack **a, t_stack **b)
{
	if (init(a) == ERROR || init(b) == ERROR)
	{
		ft_printf("Error\n");
		exit(ERROR);
	}
	return (SUCCESS);
}
