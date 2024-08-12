/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:25:03 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 21:34:55 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_min(t_stack *stack)
{
    int min;
    int i;

    min = stack->array[0];
    i = 1;
    while (i <= stack->top)
    {
        if (stack->array[i] < min)
            min = stack->array[i];
        i++;
    }
    return (min);
}

int get_max(t_stack *stack)
{
    int max;
    int i;

    max = stack->array[0];
    i = 1;
    while (i <= stack->top)
    {
        if (stack->array[i] > max)
            max = stack->array[i];
        i++;
    }
    return (max);
}

int get_index(t_stack *stack, int value)
{
    int i;

    i = 0;
    while (i <= stack->top)
    {
        if (stack->array[i] == value)
            return (i);
        i++;
    }
    return (-1);
}


