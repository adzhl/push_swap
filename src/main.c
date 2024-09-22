/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:14:47 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/22 19:14:33 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	handle_sort(t_stack **a, t_stack **b)
{
	if (!is_sorted(*a))
	{
		if (stack_size(*a) == 2)
			sa(a);
		else if (stack_size(*a) == 3)
			sort_three(a);
		else if (stack_size(*a) <= 5)
			sort_small(a, b);
		else
			sort_big(a, b);
	}
}

static char **process_arguments(int *argc, char ***argv, int *new_argc)
{
    char **split_args;

	split_args = NULL;
    if (*argc < 2)
        return (NULL);
    if (*argc == 2)
    {
        if (!(*argv)[1][0])
            handle_error(NULL, NULL, NULL);
        split_args = handle_str((*argv)[1], argc);
        *argv = split_args;
        *new_argc = *argc;
    }
    else
    {
        *new_argc = *argc - 1;
        (*argv)++;
    }
    return (split_args);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**split_args;
	int new_argc;

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
