/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:01:29 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/15 18:10:36 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *initialize_stack(int argc, char **argv, t_stack **a)
{
    int i;
    int num;
    t_stack *new_node;
    t_stack *last;

    i = 1;
    *a = NULL;
    last = NULL;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return (NULL);
        new_node->num = num;
        new_node->index = i - 1;
        new_node->above_median = 0;
        new_node->size = argc - 1;
        new_node->target = NULL;
        new_node->next = NULL;
        new_node->prev = last;
        if (last)
            last->next = new_node;
        else
            *a = new_node;
        last = new_node;
        i++;
    }
    return (*a);
}

/* // Print the stack to verify the initialization
void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("Value: %d, Index: %d, Size: %d\n", stack->num, stack->index, stack->size);
        stack = stack->next;
    }
}

int main(int argc, char **argv)
{
    t_stack *stack = NULL;

    if (argc < 2)
    {
        printf("Usage: %s num1 num2 ...\n", argv[0]);
        return 1;
    }

    stack = initialize_stack(argc, argv, &stack);

    if (!stack)
    {
        fprintf(stderr, "Failed to initialize stack.\n");
        return 1;
    }

    print_stack(stack);

    // Free the stack to avoid memory leaks
    t_stack *temp;
    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }

    return 0;
} */

