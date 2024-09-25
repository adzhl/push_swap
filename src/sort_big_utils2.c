/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:46:12 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 09:22:00 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_mean(t_stack *stack)
{
	int			count;
	long long	total;
	int			mean;

	count = 0;
	total = 0;
	while (stack)
	{
		total = total + stack->num;
		count++;
		stack = stack->next;
	}
	mean = total / count;
	return (mean);
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rr_both_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		rrr_both_b(a, b, cheapest_node);
	rotate_to_top(b, cheapest_node, 'b');
	rotate_to_top(a, cheapest_node->target, 'a');
	pa(a, b, 1);
}

void	set_cheapest_cost(t_stack **a, t_stack **b)
{
	current_index(a);
	current_index(b);
	target_for_b(*a, *b);
	find_cost_b(*a, *b);
	cheapest_cost(*b);
}
