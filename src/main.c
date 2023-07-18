/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirnavar <mirnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:25:49 by mirnavar          #+#    #+#             */
/*   Updated: 2023/07/18 19:51:28 by mirnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_stack(t_node *node)
{
    t_node *tmp;

    tmp = node;
    while (tmp)
    {
        ft_printf("the data %d\nthe index %d\n", tmp->data, tmp->index);
        tmp = tmp->next;
    }
}

int check_argv(char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;
    while (argv[i])
    {
        if (ft_strlen(argv[i]) == 1 && argv[i][j] == '-')
            return (ERROR);
        if (ft_strlen(argv[i]) == 1 && argv[i][j] == '+')
            return (ERROR);
        if (argv[i][0] == '-' || argv[i][0] == '+')
            j++;
        while (argv[i][j])
        {
            if (ft_isdigit(argv[i][j]))
                j++;
            else
                return (ERROR);
        }
        j = 0;
        i++;
    }
    return (SUCCESS);
}

int check_lim(int argc, char **argv)
{
    int i;
    int size;

    i = 1;
    while (i < argc)
    {
        size = ft_strlen(argv[i]);
        if (size == 0 || ((size > 10 && argv[i][0] != '-')
            && (size >10 && argv[i][0] != '+')) || size > 11)
            return (ERROR);
        if (argv[i][0] != '-' && size == 10 
            && ft_strncmp(argv[i], "2147483647", 10) > 0)
            return (ERROR);
        if (argv[i][0] == '-' && size == 11
            && ft_strncmp(argv[i], "-2147483648", 11) > 0)
            return (ERROR);
        if (argv[i][0] == '+' && size == 11
            && ft_strncmp(argv[i], "+2147483647", 11) > 0)
            return (ERROR);
        i++;
    }
    return (SUCCESS);
}

int check_duplicate(int argc, char **argv)
{
    int *array;
    int num;
    int next;

    array = ft_calloc(sizeof(int), argc - 1);
    if (!array)
        return (ERROR);
    num = 0;
    next = 1;
    while (next < argc)
        array[num++] = ft_atoi(argv[next++]);
    num = 0;
    while (num < argc)
    {
        next = num + 1;
        while (next < argc - 1)
        {
            if (array[num] == array[next])
            {
                free(array);
                return (ERROR);
            }
            next++;
        }
        num++;
    }
    free(array);
    return (SUCCESS);
}

int check_argumentos(int argc, char **argv)
{
    if (argc >= 2)
    {
        if (check_argv(argv) == ERROR || check_lim(argc, argv) == ERROR
        || check_duplicate(argc, argv) == ERROR)
        {
            write(2, "Error\n", 6);
            exit (ERROR);
        }
    }
    else
        exit(ERROR);
    return (SUCCESS);
}

int main(int argc, char **argv)
{
    if (!check_argumentos(argc, argv))
        ft_printf("Muy bien mireita\n");
    return (SUCCESS);
}
