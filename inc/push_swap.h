/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:39:17 by mirnavar          #+#    #+#             */
/*   Updated: 2023/06/28 12:55:29 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft.h"
# include "../lib/ft_printf.h"
# include <limits.h>

// ------------------ STRUCTURES -------------- //

  // aux node//
typedef struct s_elems
{
	int				val;
	int				index;
	struct s_elems	*next;
	struct s_elems	*prev;
	t_elems;	
}

// stack structure //
typedef s_stack
{
	int				size;
	t_node			top;
	t_node			bott;
	t_stack;
}

// ----------------- FUNCTIONS ---------------- //
// Checker: src/check.c                         //
	void	check_param(int argc, char **argv);
	int		check_argv(char **argv);
	int		check_int(int argc, char **argv);
	int		duplicated(int argc, char **argv);
	int		check_order(int argc, char **argv);

// Instruction Moves:                          //
						/*  mov/swap.c  */

						/*  mov/push.c  */

						/*  mov/rotate.c  */

						/*  mov/rev_rotate.c  */

// 
