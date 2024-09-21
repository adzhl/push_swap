/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:18:50 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/16 13:07:55 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*stack = second;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->next = NULL;
	first->prev = last;
}

/* void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
} */

void reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *second_last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = *stack;
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

/* t_stack *initialize_stack(int count, int values[])
{
	t_stack	*stack;
	t_stack	*last;
	t_stack	*new_node;

	stack = NULL;
	last = NULL;
	for (int i = 0; i < count; i++)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		if (!new_node)
			return (NULL);
		new_node->num = values[i];
		new_node->next = NULL;
		new_node->prev = last;
		if (last)
			last->next = new_node;
		else
			stack = new_node;
		last = new_node;
	}
	return (stack);
}

// Print the stack
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Value: %d\n", stack->num);
		stack = stack->next;
	}
	printf("----\n");
}

// Main function to test push operation
void	test_push(void)
{
	int		values_src[] = {1, 2, 3};
	int		values_dst[] = {4, 5};
	t_stack	*src;
	t_stack	*dst;

	src = initialize_stack(3, values_src);
	dst = initialize_stack(2, values_dst);
	printf("Before push:\n");
	printf("Source stack:\n");
	print_stack(src);
	printf("Destination stack:\n");
	print_stack(dst);
	push(&dst, &src);
	printf("After push:\n");
	printf("Source stack:\n");
	print_stack(src);
	printf("Destination stack:\n");
	print_stack(dst);
	// Cleanup memory
	while (src) { t_stack *temp = src; src = src->next; free(temp); }
	while (dst) { t_stack *temp = dst; dst = dst->next; free(temp); }
}

// Main function to test swap operation
void	test_swap(void)
{
	int		values[] = {1, 2, 3};
	t_stack	*stack;

	stack = initialize_stack(3, values);
	printf("Before swap:\n");
	print_stack(stack);
	swap(&stack);
	printf("After swap:\n");
	print_stack(stack);
	// Cleanup memory
	while (stack) { t_stack *temp = stack; stack = stack->next; free(temp); }
}

// Main function to test rotate operation
void	test_rotate(void)
{
	int		values[] = {1, 2, 3};
	t_stack	*stack;

	stack = initialize_stack(3, values);
	printf("Before rotate:\n");
	print_stack(stack);
	rotate(&stack);
	printf("After rotate:\n");
	print_stack(stack);
	// Cleanup memory
	while (stack) { t_stack *temp = stack; stack = stack->next; free(temp); }
}

// Main function to test reverse_rotate operation
void	test_reverse_rotate(void)
{
	int		values[] = {1, 2, 3};
	t_stack	*stack;

	stack = initialize_stack(3, values);
	printf("Before reverse rotate:\n");
	print_stack(stack);
	reverse_rotate(&stack);
	printf("After reverse rotate:\n");
	print_stack(stack);
	// Cleanup memory
	while (stack) { t_stack *temp = stack; stack = stack->next; free(temp); }
}

// Main function to run all tests
int	main(void)
{
	printf("Testing push:\n");
	test_push();
	printf("Testing swap:\n");
	test_swap();
	printf("Testing rotate:\n");
	test_rotate();
	printf("Testing reverse rotate:\n");
	test_reverse_rotate();

	return (0);
} */
