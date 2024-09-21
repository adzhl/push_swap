/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:01:29 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/13 10:15:12 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// find last node
static t_stack	*last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

// create new node
static t_stack	*create_node(int n)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = n;
	new_node->next = NULL;
	return (new_node);
}

void	append_node(t_stack **stack, int num)
{
	t_stack	*last;
	t_stack	*new;

	new = create_node(num);
	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

/* void	initialize_stack(char **argv, t_stack **a)
{
	int	i;
	int	num;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		append_node(a, (int)num);
		i++;
	}
} */
/* void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->num);
		stack = stack->next;
	}
	printf("\n");
}

// Main function to test the stack operations
int	main(int argc, char **argv)
{
	(void)argc;
	t_stack *stack = NULL;

	// Initialize the stack with values from command-line arguments
	initialize_stack(argv + 1, &stack); // Skip the program name

	// Print the stack to verify it contains the expected values
	print_stack(stack);

	// Free the stack nodes
	t_stack *tmp;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}

	return (0);
} */
