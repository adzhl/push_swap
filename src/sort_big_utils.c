/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:13:32 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/21 15:44:35 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    rotate_to_top(t_stack **stack, t_stack *top, char stack_name)
{
    while (*stack != top)
    {
        if (stack_name == 'a')
        {
            if (top->above_median)
                rotate_a(stack);
            else
                rr_a(stack);
        }
        else if (stack_name == 'b')
        {
            if (top->above_median)
                rotate_b(stack);
            else
                rr_b(stack);
        }
    }
}

void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node) 
		rotate_ab(a, b);
	current_index(a);
	current_index(b);
}

void	rev_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rrr(a, b);
	current_index(a);
	current_index(b);
}

void	rr_both_b(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node) 
		rotate_ab(a, b);
	current_index(a);
	current_index(b);
}

void	rrr_both_b(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rrr(a, b);
	current_index(a);
	current_index(b);
}

void prepare_stack_a(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		rev_rotate_both(a, b, cheapest_node);
	rotate_to_top(a, cheapest_node, 'a');
	rotate_to_top(b, cheapest_node->target, 'b');
	push_b(a, b);
} 

void prepare_stack_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rr_both_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target->above_median))
		rrr_both_b(a, b, cheapest_node);
	rotate_to_top(b, cheapest_node, 'b');
	rotate_to_top(a, cheapest_node->target, 'a');
	push_a(a, b);
} 

void min_to_top(t_stack **a)
{
	t_stack *smallest;

	smallest = find_smallest(*a);
	while ((*a)->num != smallest->num)
	{
		if (smallest->above_median)
			rotate_a(a);
		else
			rr_a(a);
	}
}


