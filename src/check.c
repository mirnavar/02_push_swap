/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:14:27 by mirnavar          #+#    #+#             */
/*   Updated: 2023/06/27 17:09:44 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_param(int argc, char **argv)
{
	if (!check_argv(argv))
		ft_error(0);
	if (!check_int(argc, argv))
		ft_error(0);
	if (!duplicated(argc, argv))
		ft_error(0);
	if (chec
}

int	check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;

	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 1 && argv[i][j] == '-')
			return(0);
		if (ft_strlen(argv[i]) == 1 && argv[i][j] == '+')
	   		return(0)
		if (argv[i][0] == '-' || argv[i] == '+')
			j++;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j])
				j++;
			else
				return(0);
		}	
		j = 0;
		i++;
	}
	return(1);
}

int	check_int(int argc, char **argv)
{
	int	i;
	int	size;

	i = 1;
	while (i < argc)
	{
		size = ft_strlen(argv[i]);
		if (size == 0 || ((size > 10 && arvg[i][0] != '-') 
					&& (size > 10 && argv[i][0] != '+')) || size > 11)
			return(0);
		if (argv[i][0] != '-' && size == 10
				&& ft_strncmp(argv[i], "2147483647", 10) > 0)
			return(0);
		if (argv[i][0] == '-' && size == 11
				&& ft_strncmp(argv[i], "-2147483648", 11) > 0)
			return(0);
		if (argv[i][0] == '+' && size == 11
				&& ft_strncmp(argv[i], "+2147483647", 11) > 0)
			return(0);
		i++;
	}
	return (1);
}

int duplicated(int argc, char **argv)
{
	int *stack;
	int	num;
	int	next;

	stack = ft_calloc(argc -1, sizeof(int));
	if (!stack)
		return (0);
	num = 0;
	next = 1;
	while (next < argc)
		stack[num++] = ft_atoi(argv[next++]);
	num = 0;
	while (num < argc)
	{
		next = num + 1;
		while (next < argc - 1)
		{
			if (stack[num] == stack[next])
				return(0);
			next++;
		}
		num++;
	}	
	free(stack);
	return(1);
}

