/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:21:15 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/23 07:31:32 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_cost_b(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (b->above_median)
			b->cost = b->index;
		else
			b->cost = size_b - b->index;
		if (b->target->above_median)
			b->cost += b->target->index;
		else
			b->cost += size_a - b->target->index;
		b = b->next;
	}
}

void	cheapest_cost(t_stack *stack)
{
	long	min_cost;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	min_cost = LONG_MAX;
	if (!stack)
		return ;
	while (stack)
	{
		if (stack->cost < min_cost)
		{
			min_cost = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

t_stack	*get_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
