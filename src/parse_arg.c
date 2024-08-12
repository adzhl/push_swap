/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:01:29 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 19:50:44 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void initialize_stack(int argc, t_stack *stack_a)
{
    stack_a->size = argc - 1;
    stack_a->array = malloc(sizeof(int) * stack_a->size);
    if (!stack_a->array)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    stack_a->top = -1;
}

int check_dup(t_stack *stack, int num)
{
    int j;

    j = 0;
    while (j <= stack->top)
    {
        if (stack->array[j] == num)
            return (1);
        j++;
    }
    return (0);
}

int parse_single_arg(char *arg, t_stack *stack_a)
{
    long num;
    char *endptr;

    if (invalid_input(arg) || !valid_int(arg))
        return (0);
    num = ft_strtol(arg, &endptr, 10);
    if (*endptr != '\0' || num > INT_MAX || num < INT_MIN)
        return (0);
    if (check_dup(stack_a, (int)num))
        return (0);
    push(stack_a, (int)num);
    return (1);
}

void parse_arg(int argc, char **argv, t_stack *stack_a)
{
    int i;

    initialize_stack(argc, stack_a);
    i = 1;
    while (i < argc)
    {
        if (!parse_single_arg(argv[i], stack_a))
        {
            write(2, "Error\n", 6);
            exit(1);
        }
        i++;
    }
}
