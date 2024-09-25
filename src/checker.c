/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 07:41:43 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 12:12:40 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
	process_instructions(&a, &b);
	cleanup(a, b, split_args);
	return (0);
}
