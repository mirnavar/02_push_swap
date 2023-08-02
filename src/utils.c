/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:29:03 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/02 12:34:18 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		ft_printf("the data %d\nthe index %d\n", tmp->data, tmp->index);
		ft_printf("actual %p\n next %p\n prev %p\n", tmp, tmp->next, tmp->prev);
		tmp = tmp->next;
	}
}
