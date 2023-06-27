/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:55:00 by mirnavar          #+#    #+#             */
/*   Updated: 2023/06/16 11:49:55 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc <= 1)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		ft_error(0)
	check(argc, argv);

}