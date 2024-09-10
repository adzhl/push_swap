/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:46:49 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/14 22:23:50 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push_a(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void push_b(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}

void swap_a(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void swap_b(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}