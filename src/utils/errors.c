/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 11:57:27 by mirnavar          #+#    #+#             */
/*   Updated: 2023/06/27 12:09:14 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_error(int num)
{
	if (num == 0)
		write(2, "Error\n", 6);
	else if (num == 1)
		write(2, "Error\n", 6);
	else if (num == 2)
		write(2, "Error\n", 6);
	else if (num == 3)
		write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
