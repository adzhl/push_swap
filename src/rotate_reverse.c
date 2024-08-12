/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:52:03 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 15:55:03 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void rotate_a(t_stack *a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rotate_b(t_stack *b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void rr_a(t_stack *a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void rr_b(t_stack *b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}