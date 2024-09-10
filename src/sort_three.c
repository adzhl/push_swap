/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:58:48 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/28 18:08:30 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void case1(t_stack **a, int middle, int bottom)
{
    if (middle > bottom)
    {
        rotate_a(a);
        swap_a(a);
    }
    else
        rotate_a(a);
}

static void case2(t_stack **a, int top, int bottom)
{
    if (top > bottom)
        rr_a(a);
    else
    {
        rr_a(a);
        swap_a(a);
    }
}

static void case3(t_stack **a, int top, int middle)
{
    if (top > middle)
        swap_a(a);
}

void sort_three(t_stack **a)
{
    int top;  
    int middle;  
    int bottom;  

    if (!a || !*a || !(*a)->next || !(*a)->next->next)  
        return;  
    top = (*a)->num;  
    middle = (*a)->next->num;  
    bottom = (*a)->next->next->num;  
    if (top > middle && top > bottom)  
        case1(a, middle, bottom);
    else if (middle > top && middle > bottom)  
        case2(a, top, bottom);
    else if (bottom > top && bottom > middle)
        case3(a, top, middle);
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
    return node;
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("Value: %d\n", stack->num);
        stack = stack->next;
    }
    printf("----\n");
}

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
    t_stack *a = NULL;
    t_stack *node1, *node2, *node3;

    // Create a stack with 3 elements
    node1 = create_node(34);
    node2 = create_node(0);
    node3 = create_node(100);
    
    // Link the nodes
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    
    a = node1;  // Stack a: 3 -> 1 -> 2

    printf("Stack before sorting:\n");
    print_stack(a);
    
    sort_three(&a);
    
    printf("Stack after sorting:\n");
    print_stack(a);

    // Free the stack
    free_stack(a);

    return 0;
} */





