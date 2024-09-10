/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:05:48 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/28 16:58:41 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

int is_above_median(t_stack *stack, t_stack *node)
{
    int size;
    int position;

    size = stack_size(stack);
    position = 0;
    while (stack != node)
    {
        position++;
        stack = stack->next;
    }
    return (position < size / 2);
}

void set_target(t_stack *a, t_stack *b)
{
    t_stack *current_b;
    t_stack *target;
    int closest_smaller;
    t_stack *largest;

    while (a)
    {
        target = NULL;
        closest_smaller = INT_MIN;
        current_b = b;
        largest = b;

        while (current_b)
        {
            if (current_b->num < a->num && current_b->num > closest_smaller)
            {
                closest_smaller = current_b->num;
                target = current_b;
            }
            if (current_b->num > largest->num)
                largest = current_b;
            current_b = current_b->next;
        }    

        a->target = target ? target : largest;
        a = a->next;
    }
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->num > stack->next->num)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/* t_stack *create_node(int num)
{
    t_stack *node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    node->num = num;
    node->next = NULL;
    node->prev = NULL;
    node->target = NULL; // Initialize target to NULL
    return node;
}

// Print the stack along with the targets
void print_stack_with_targets(t_stack *a)
{
    while (a)
    {
        printf("Value: %d", a->num);
        if (a->target)
            printf(", Target: %d", a->target->num);
        else
            printf(", Target: NULL");
        printf("\n");
        a = a->next;
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
    // Initialize stack a with some values
    t_stack *a = create_node(10);
    a->next = create_node(5);
    a->next->prev = a;
    a->next->next = create_node(20);
    a->next->next->prev = a->next;

    // Initialize stack b with some values
    t_stack *b = create_node(15);
    b->next = create_node(8);
    b->next->prev = b;
    b->next->next = create_node(25);
    b->next->next->prev = b->next;

    printf("Stack A before setting targets:\n");
    print_stack_with_targets(a);

    printf("Stack B:\n");
    print_stack_with_targets(b);

    // Apply set_target
    set_target(a, b);

    printf("Stack A after setting targets:\n");
    print_stack_with_targets(a);

    // Free memory
    free_stack(a);
    free_stack(b);

    return 0;
} */




