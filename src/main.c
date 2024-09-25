/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:14:47 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 12:02:29 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	handle_sort(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_size(*a) == 2)
			sa(a, 1);
		else if (stack_size(*a) == 3)
			sort_three(a);
		else if (stack_size(*a) <= 5)
			sort_small(a, b);
		else
			sort_big(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;
	int		new_argc;

	a = NULL;
	b = NULL;
	split_args = process_arguments(&argc, &argv, &new_argc);
	if (!split_args && argc < 2)
		return (0);
	if (!valid_input(new_argc, argv, &a))
		handle_error(a, b, split_args);
	handle_sort(&a, &b);
	cleanup(a, b, split_args);
	return (0);
}
