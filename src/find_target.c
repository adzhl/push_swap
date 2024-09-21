/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:11:19 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/19 13:14:00 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void target_for_a(t_stack *a, t_stack *b)
{
	t_stack *target_b;
    t_stack *current_b;
    long closest;

    target_b = NULL;
	while (a)
	{
		current_b = b;
		closest = LONG_MIN;
		while (current_b)
		{
			if (current_b->num < a->num && current_b->num > closest)
			{
				closest = current_b->num;
				target_b = current_b;
			}
			current_b = current_b->next;
		}
		if (closest == LONG_MIN)
			a->target = find_largest(b);
		else
			a->target = target_b;
		a = a->next;
	}
}

void target_for_b(t_stack *a, t_stack *b)
{
	t_stack *target_a;
    t_stack *current_a;
    long closest;

    target_a = NULL;
	while (b)
	{
		current_a = a;
		closest = LONG_MAX;
		while (current_a)
		{
			if (current_a->num > b->num && current_a->num < closest)
			{
				closest = current_a->num;
				target_a = current_a;
			}
			current_a = current_a->next;
		}
		if (closest == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target_a;
		b = b->next;
	}
}

