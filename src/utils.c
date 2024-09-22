/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:05:48 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/22 13:45:05 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int is_sorted(t_stack *stack)
{
    if (!stack)
        return (0);
    while (stack && stack->next)
    {
        if (stack->num > stack->next->num)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void current_index(t_stack **stack)
{
    t_stack *current;
    int size;
    int i;

    size = stack_size(*stack);
    current = *stack;
    i = 0;
    while (current)
    {
        current->index = i;
        current->above_median = (i < size / 2);
        current = current->next;
        i++;
    }
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	smallest = stack;
	current = stack;
	while (current)
	{
		if (current->num < smallest->num)
			smallest = current;
		current = current->next;
	}
	return (smallest);
}

t_stack	*find_largest(t_stack *stack)
{
	t_stack	*largest;
	t_stack	*current;

	largest = stack;
	current = stack;
	while (current)
	{
		if (current->num > largest->num)
			largest = current;
		current = current->next;
	}
	return (largest);
}
