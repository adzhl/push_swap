/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:14:47 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/21 15:42:20 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	handle_sort(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_size(*a) == 2)
			swap_a(a);
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
	int new_argc;

	a = NULL;
	b = NULL;
	split_args = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		split_args = handle_str(argv[1], &argc);
		argv = split_args;
		new_argc = argc;
	}
	else
	{
		new_argc = argc - 1;
		argv++;
	}
	if (!valid_input(new_argc, argv, &a))
		handle_error(split_args, a, b);
	handle_sort(&a, &b);
	cleanup(a, b, split_args);
	return (0);
}
