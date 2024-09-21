/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:25:27 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/19 10:16:50 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Helper function to rotate the stack until the target node is on top
static void	rotate_top(t_stack **stack, t_stack *target)
{
	int		size;
	int		pos;
	t_stack	*current;

	size = stack_size(*stack);
	pos = 0;
	current = *stack;
	while (current != target)
	{
		pos++;
		current = current->next;
	}
	if (pos <= size / 2)
	{
		while (*stack != target)
			rotate_a(stack);
	}
	else
	{
		while (*stack != target)
			rr_a(stack);
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*smallest;

	size = stack_size(*a);
	while (size > 3 && !is_sorted(*a))
	{
		smallest = find_smallest(*a);
		rotate_top(a, smallest);
		push_b(a, b);
		size--;
	}
	if (!is_sorted(*a))
		sort_three(a);
	while (*b)
		push_a(a, b);
}
