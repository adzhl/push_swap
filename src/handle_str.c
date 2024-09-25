/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:27:44 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 08:24:45 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_only_spaces(const char *str)
{
	while (*str)
	{
		if (!((*str >= 9 && *str <= 13) || *str == ' '))
			return (0);
		str++;
	}
	return (1);
}

char	**handle_str(char *arg, int *argc)
{
	char	**split_args;
	int		i;

	if (is_only_spaces(arg))
		handle_error(NULL, NULL, NULL);
	split_args = ft_split(arg, ' ');
	if (!split_args)
		handle_error(NULL, NULL, split_args);
	i = 0;
	while (split_args[i])
		i++;
	*argc = i;
	return (split_args);
}
