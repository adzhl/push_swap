/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:20:23 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 09:21:22 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_by_mean(t_stack **a, t_stack **b)
{
	int	size_a;
	int	mean;

	size_a = stack_size(*a);
	mean = get_mean(*a);
	while (size_a > 5 && !is_sorted(*a))
	{
		if ((*a)->num < mean)
		{
			pb(a, b, 1);
			size_a--;
			mean = get_mean(*a);
		}
		else
			ra(a, 1);
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	sort_by_mean(a, b);
	sort_small(a, b);
	while (*b)
	{
		set_cheapest_cost(a, b);
		push_b_to_a(a, b);
	}
	current_index(a);
	if (!is_sorted(*a))
		min_to_top(a);
}
