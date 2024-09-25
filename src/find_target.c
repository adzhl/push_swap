/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:11:19 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/23 07:28:58 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	target_for_b(t_stack *a, t_stack *b)
{
	t_stack	*target_a;
	t_stack	*current_a;
	long	closest;

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
