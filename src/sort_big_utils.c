/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:13:32 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 09:21:52 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_to_top(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	rr_both_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, 1);
	current_index(a);
	current_index(b);
}

void	rrr_both_b(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, 1);
	current_index(a);
	current_index(b);
}

void	min_to_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = find_smallest(*a);
	while ((*a)->num != smallest->num)
	{
		if (smallest->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}
