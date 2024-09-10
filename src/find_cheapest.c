/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:48:19 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/28 19:17:43 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* void calculate_cost(t_stack *a, t_stack *b, t_move *move)
{
    int size_a;
    int size_b;
    int cost_a;
    int cost_b;

    size_a = stack_size(a);
    size_b = stack_size(b);
    cost_a = 0;
    cost_b = 0;
    if (b->index <= size_b / 2)
        cost_b = b->index;
    else
        cost_b = size_b - b->index;

    if (b->target->index <= size_a / 2)
        cost_a = b->target->index;
    else
        cost_a = size_a - b->target->index;

    move->cost = cost_a + cost_b;
}

void find_cheapest(t_stack *a, t_stack *b, t_move *move)
{
    t_stack *current;
    t_move temp_move;
    
    set_target(a, b);
    current = b;
    move->cost = INT_MAX;
    move->cheapest = NULL;
    while (current)
    {
        calculate_cost(a, current, &temp_move);
        if (temp_move.cost < move->cost)
        {
            move->cost = temp_move.cost;
            move->cheapest = current;
        }
        current = current->next;
    }
}

void execute_cheapest(t_stack **a, t_stack **b, t_move *move)
{
    while (*b != move->cheapest)
    {
        if (is_above_median(*b, move->cheapest))
            rotate_b(b);
        else
            rr_b(b);
    }
    while ((*a) != move->cheapest->target)
    {
        if (is_above_median(*a, move->cheapest->target))
            rotate_a(a);
        else
            rr_a(a);
    }
    push_a(b, a);
} */

static void cost_analysis_a(t_stack *a, t_stack *b, t_move *move)
{
    int len_a = stack_size(a); // Length of stack `a`
    int len_b = stack_size(b); // Length of stack `b`
    int min_cost = INT_MAX; // Initialize minimum cost to a very high value
    t_stack *best_node = NULL; // Pointer to store the best node

    while (a) // Iterate through each node in stack `a`
    {
        int cost_a = a->index; // Base cost to move node `a` to the top
        int cost_b;

        // Calculate the cost to move node `a` to the top of stack `a`
        if (!a->above_median) // If the node is below the median
            cost_a = len_a - a->index; // Cost to move from bottom to top

        // Calculate the cost to move the target node from stack `b` to the top
        if (a->target->above_median) // If the target node in stack `b` is above median
            cost_b = a->target->index; // Cost to move target node from top
        else // If the target node in stack `b` is below median
            cost_b = len_b - a->target->index; // Cost to move target node from bottom to top

        int total_cost = cost_a + cost_b; // Total cost to move both nodes

        // Update the best node if a cheaper cost is found
        if (total_cost < min_cost)
        {
            min_cost = total_cost; // Update minimum cost
            best_node = a; // Update the best node
        }

        a = a->next; // Move to the next node in stack `a`
    }

    // Set the result in the move structure
    if (best_node)
    {
        move->cheapest = best_node; // Store the node with the minimum cost
        move->cost = min_cost; // Store the minimum cost
    }
}

