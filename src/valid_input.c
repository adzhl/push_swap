/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:42:39 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/13 10:16:35 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	valid_int(char *str)
{
	int	has_digits;

	has_digits = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str == '0')
		str++;
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		has_digits = 1;
		str++;
	}
	return (has_digits);
}

static int	check_dup(t_stack *stack, int value)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		if (current->num == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	free_and_return(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	handle_error(NULL, NULL, NULL);
	return (0);
}

int	valid_input(int argc, char **argv, t_stack **a)
{
	int		i;
	long	nbr;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0')
			return (free_and_return(*a));
		if (!valid_int(argv[i]))
			return (free_and_return(*a));
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (free_and_return(*a));
		if (check_dup(*a, (int)nbr))
			return (free_and_return(*a));
		append_node(a, (int)nbr);
		i++;
	}
	return (1);
}

/* int	main(int argc, char **argv)
{
	int	result;

	// Test cases
	result = valid_input(argc, argv);
	if (result)
		printf("Valid input.\n");
	else
		printf("Invalid input.\n");
	return (0);
} */
