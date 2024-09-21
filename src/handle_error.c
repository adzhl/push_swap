/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 21:00:57 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/11 13:01:07 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_split_args(char **split_args)
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

int	handle_error(char **split_args, t_stack *a, t_stack *b)
{
	if (split_args)
		free_split_args(split_args);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	cleanup(t_stack *a, t_stack *b, char **split_args)
{
	int		i;
	t_stack	*temp;

	if (split_args)
	{
		i = 0;
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
	}
	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	while (b)
	{
		temp = b;
		b = b->next;
		free(temp);
	}
}

/* int isqrt(int n)
{
	int x;
	int y;

	if (n <= 1)
		return (n);
	x = n;
	y = (x + 1) / 2;
	while (y < x)
	{
		x = y;
		y = (x + n / x) / 2;
	}
	return (x);
} */
