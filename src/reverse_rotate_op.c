/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:52:03 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 09:17:59 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack **a, int print)
{
	reverse_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	reverse_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
