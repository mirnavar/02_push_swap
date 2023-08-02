/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:21:11 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/02 12:00:06 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	size_three(t_stack *a)
{
	while (!stack_sorted(a, ASC))
	{
		if (find_num(a, 0) == 0 && find_num(a, 2) == 1) 
			reverse_rotate(a, STACKA);
		else if (find_num(a, 1) == 0 && find_num(a, 0) == 2)
			reverse_rotate(a, STACKA);
		else if (find_num(a, 2) == 0 && find_num(a, 0) == 2)
			swap(a, STACKA);
		else if (find_num(a, 1) == 0 && find_num(a, 0) == 1)
			swap(a, STACKA);
		else if (find_num(a, 2) == 0 && find_num(a, 0) == 1)
			rotate(a, STACKA);
	}
	return (SUCCESS);
}

int	size_four(t_stack *a, t_stack *b)
{
	int	idx;

	idx = a->size - 1;
	while (a->size != 3)
	{
		if (a->top->index == idx)
			push(a, b, STACKB);
		else if (find_num(a, 3) == 1)
			swap(a, STACKA);
		else if (find_num(a, 3) == 2)
			rotate(a, STACKA);
		else
			reverse_rotate(a, STACKA);
	}
	size_three(a);
	push(b, a, STACKA);
	rotate(a, STACKA);
	return (SUCCESS);
}

int	size_five(t_stack *a, t_stack *b)
{
	int	idx;

	idx = a->size - 1;
	while (a->size != 3)
	{
		if (a->top->index == idx || a->top->index == (idx - 1))
			push(a, b, STACKB);
		else if (find_num(a, 3) == 1 || find_num(a, 4) == 1)
			swap(a, STACKA);
		else if (find_num(a, 3) >= 2 || find_num(a, 4) >= 2)
			reverse_rotate(a, STACKA);
	}
	size_three(a);
	if (!stack_sorted(b, ASC))
		swap(b, STACKB);
	while (b->size)
	{
		push(b, a, STACKA);
		rotate(a, STACKA);
	}
	return (SUCCESS);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;

	size = a->size;
	max_num = size - 1;
	max_bits = 0;
	while (max_num)
	{
		max_num = max_num >> 1;
		max_bits++;
	}
	i = 0;
	while (i < max_bits)
	{
		sort_digits(a, b, i);
		while (b->size)
			push(b, a, STACKA);
		i++;
	}
}

void	sort_digits(t_stack *a, t_stack *b, int bit)
{
	int	num;
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		num = a->top->index;
		if ((num >> bit) & 1)
			rotate(a, STACKA);
		else 
			push(a, b, STACKB);
		i++;
	}
}
