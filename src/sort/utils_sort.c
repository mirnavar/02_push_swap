/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:36:10 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/01 20:44:32 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_num(t_stack *stack, int ind)
{
	t_node	*node;
	int		pos;

	pos = 0;
	node = stack->top;
	while (node)
	{
		if (node->index == ind)
			break ;
		node = node->next;
		pos++;
	}
	return (pos);
}
