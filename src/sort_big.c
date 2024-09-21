/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:20:23 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/21 15:48:46 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_mean(t_stack *stack)
{
    int count;
    long long total;
    int mean;

	count = 0;
    total = 0;
    while (stack)
    {
        total = total + stack->num;
        count++;
        stack = stack->next;
    }
    mean =  total / count;
    return (mean);
}

void sort_by_mean(t_stack **a, t_stack **b)
{
    int size_a;
    int mean;

    size_a = stack_size(*a);
    mean = get_mean(*a);
    while (size_a > 3 && !is_sorted(*a))
    {
        if ((*a)->num < mean)
        {
            push_b(a, b);
            size_a--;
            mean = get_mean(*a);
        }
        else
            rotate_a(a);
    }
}

static void move_b_to_a(t_stack **a, t_stack **b)
{
	current_index(a);
	current_index(b);
	target_for_b(*a, *b);
    find_cost_b(*a, *b);
    cheapest_cost(*b);
}

void sort_big(t_stack **a, t_stack **b)
{
    sort_by_mean(a, b);
    sort_three(a);
	while (*b)
	{
		move_b_to_a(a, b);
        prepare_stack_b(a, b);
	}
	current_index(a);
	if (!is_sorted(*a))
		min_to_top(a);
}
