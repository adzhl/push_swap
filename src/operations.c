/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:18:50 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 15:42:31 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push(t_stack *stack, int value)
{
    stack->top++;
    stack->array[stack->top] = value;
}

/**
 * removes the top element of a stack and return the value
 */
int pop(t_stack *stack)
{
    if (stack->top < 0)
        return (INT_MIN);
    return (stack->array[stack->top--]);
}

void swap(t_stack *stack)
{
    int temp;

    if (stack->top < 1)
        return ;
    temp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = temp;
}

void rotate(t_stack *stack)
{
    int temp;
    int i;

    if (stack->top < 1)
        return;
    temp = stack->array[stack->top];
    i = stack->top;
    while (i > 0)
    {
        stack->array[i] = stack->array[i - 1];
        i--;
    }
    stack->array[0] = temp;
}

void reverse_rotate(t_stack *stack)
{
    int temp;
    int i;

    if (stack->top < 1)
        return;
    temp = stack->array[0];
    i = 0;
    while (i < stack->top)
    {
        stack->array[i] = stack->array[i + 1];
        i++;
    }
    stack->array[stack->top] = temp;
}
