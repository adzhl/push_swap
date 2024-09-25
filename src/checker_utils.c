/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:59:30 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 10:14:56 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	execute_instruction(t_stack **a, t_stack **b, char *instruction)
{
	if (!ft_strncmp(instruction, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(instruction, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		rrr(a, b, 0);
	else
		handle_error(NULL, NULL, NULL);
}

void	process_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_instruction(a, b, line);
		free(line);
	}
	free(line);
	if (is_sorted(*a) && !*b)
		write(1, "OK\n", 3);
	else if (!is_sorted(*a))
		write(1, "KO\n", 3);
}
