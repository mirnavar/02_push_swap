/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:39:17 by mirnavar          #+#    #+#             */
/*   Updated: 2023/06/14 18:17:01 by mirnavar         ###   ########.fr       */
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
	int		data;
	int		index;
}
