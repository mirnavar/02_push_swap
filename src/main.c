/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:25:49 by mirnavar          #+#    #+#             */
/*   Updated: 2023/08/01 20:41:03 by mirnavar         ###   ########.fr       */
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

int	setup_stack(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = argc - 1;
	while (i)
		push_stack(stack, ft_atoi(argv[i--]), 0);
	return (SUCCESS);
}

void	indexer(t_stack *stack)
{
	t_node	*tmp;
	t_node	*current;
	int		idx1;
	int		idx2;

	current = stack->top;
	idx2 = -1;
	while (++idx2 < stack->size)
	{
		idx1 = 0;
		tmp = stack->top;
		while (tmp)
		{
			if (tmp->data < current->data)
				idx1++;
			tmp = tmp->next;
		}
		current->index = idx1;
		current = current->next;
	}
}

int	stack_size(t_stack *a, t_stack *b)
{
	(void)b;
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
	if (a->size > 5)
	{
		sort_big(a, b);
		return (SUCCESS);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	check_argumentos(argc, argv);
	doble_init(&a, &b);
	setup_stack(argc, argv, a);
	indexer(a);
	if (stack_sorted(a, ASC) != 0)
	{
		doble_free(a, b);
		return (SUCCESS);
	}
	stack_size(a, b);
	doble_free(a, b);
	return (SUCCESS);
}

//int main(int argc, char **argv)
//{
//    t_stack *a;
//    t_stack *b;
//    if (!check_argumentos(argc, argv))
//        ft_printf("Muy bien mireita\n");
//    doble_init(&a, &b);
//    //int i = 8;
//    //int j = 1;
//    //while (i <= 15)
//    //    push_stack(a, i++, j++);
//    //write(2, "stacka1\n", 8);
//    //print_stack(a);
//    ////pop_stack(a);
//    //push(a, b, STACKB);
//    //write(2, "stacka2\n", 8);
//    //print_stack(a);
//    //write(2, "stackb\n", 7);
//    //print_stack(b);
//    //swap(a, STACKA);
//    //print_stack(a);
//    //push(a, b, STACKB);
//    //swap(b, STACKB);
//    //print_stack(b);
//    ////print_stack(a->top->next);
//    //doble_rotate(a, b);
//    //reverse_rotate(a, STACKA);
//    //push(a, b, STACKB);
//    //push(a, b, STACKB);
//    //push(a, b, STACKB);
//    //print_stack(b);
//    //doble_reverse_rotate(a, b);
//    //write(1, "aqui final\n", 11);
//    //write(1, "STACK A\n", 7);
//    //print_stack(a);
//    //write(1, "STACK B\n", 7);
//    //print_stack(b);
//    setup_stack(argc, argv, a);
//    write(1, "SETUP COMPLETADO\n", 17);
//	indexer(a);
//	//print_stack(a);
//	if (stack_sorted(a, ASC) != 0)
//	{
//		doble_free(a, b);
//		ft_printf("esta ordenado");
//		return (SUCCESS);
//	}
//	write(1, "SEGUIMOS!\n", 10);
//	stack_size(a, b);
//	print_stack(a);
//ft_printf("%d\n", ((4>>2)&1));
//    doble_free(a, b);
//    return (SUCCESS);
//}

//int main(int argc, char **argv)
//{
//    t_stack *a;
//    t_stack *b;
//    (void)argc;
//    (void)argv;
//    //if (!check_argumentos(argc, argv))
//    //    ft_printf("Muy bien mireita\n");
//    doble_init(&a, &b);
//    int i = 5;
//    int j = 1;
//    while (i <= 15)
//        push_stack(a, i++, j++);
//    while (!push(a, b, STACKB))
//        ;
//    print_stack(b);
//    while (b->size > 0)
//        push(b, a, STACKA);
//    print_stack(a);
//    doble_free(a, b);
//    return (SUCCESS);
//}
