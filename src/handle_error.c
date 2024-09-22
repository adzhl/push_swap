/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 21:00:57 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/22 18:22:10 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	free_split_args(char **split_args)
{
	int	i;

	if (!split_args)
		return ;
	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	handle_error(t_stack *a, t_stack *b, char **split_args)
{
	cleanup(a, b, split_args);
	write(2, "Error\n", 6);
	exit(1);
}

void	cleanup(t_stack *a, t_stack *b, char **split_args)
{
	if (split_args)
		free_split_args(split_args);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}
