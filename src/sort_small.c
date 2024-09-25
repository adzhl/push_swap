/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:25:27 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 09:20:51 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	bring_to_top(t_stack **stack, t_stack *target)
{
	int		size;
	int		i;
	t_stack	*current;

	size = stack_size(*stack);
	i = 0;
	current = *stack;
	while (current != target)
	{
		i++;
		current = current->next;
	}
	if (i <= size / 2)
	{
		while (*stack != target)
			ra(stack, 1);
	}
	else
	{
		while (*stack != target)
			rra(stack, 1);
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	t_stack	*largest;
	int		size;

	size = stack_size(*a);
	largest = find_largest(*a);
	bring_to_top(a, largest);
	pb(a, b, 1);
	if (size == 5)
	{
		smallest = find_smallest(*a);
		bring_to_top(a, smallest);
		pb(a, b, 1);
	}
	sort_three(a);
	pa(a, b, 1);
	if (size == 5)
		pa(a, b, 1);
	ra(a, 1);
}
