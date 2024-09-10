/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:06:07 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/28 19:25:04 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void push_to_b(t_stack **a, t_stack **b)
{
    while (stack_size(*a) > 3)
    {
        push_b(a, b);
    }
}

static void sort_b_to_a(t_stack **a, t_stack **b)
{
    t_move move;
    
    while (*b)
    {
        find_cheapest(*a, *b, &move);
        execute_cheapest(a, b, &move);
    }
}

void sort_stacks(t_stack **a, t_stack **b)
{
    if (stack_size(*a) > 3)
        push_a(a, b);
    if (stack_size(*a) > 3)
        push_a(a, b);
    push_to_b(a, b);
    sort_three(a);
    sort_b_to_a(a, b);
    while (!is_sorted(*a))
        rotate_a(a);
}

t_stack *create_node(int num)
{
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    node->num = num;
    node->index = 0;
    node->next = NULL;
    node->prev = NULL;
    node->target = NULL; // Initialize target to NULL
    return node;
}

// Print the stack
void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("Value: %d\n", stack->num);
        stack = stack->next;
    }
    printf("----\n");
}

// Free the memory of the stack
void free_stack(t_stack *stack)
{
    t_stack *temp;
    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main()
{
    t_stack *a = NULL; // Initialize stack a
    t_stack *b = NULL; // Initialize stack b

    // Populate stack a with unsorted values
    a = create_node(42);
    a->next = create_node(17);
    a->next->prev = a;
    a->next->next = create_node(33);
    a->next->next->prev = a->next;
    a->next->next->next = create_node(5);
    a->next->next->next->prev = a->next->next;

    // Print stack a before sorting
    printf("Stack A before sorting:\n");
    print_stack(a);

    // Sort the stacks
    sort_stacks(&a, &b);

    // Print stack a after sorting
    printf("Stack A after sorting:\n");
    print_stack(a);

    // Free memory
    free_stack(a);
    free_stack(b);

    return 0;
}
