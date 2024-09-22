/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:27:44 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/22 18:20:07 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**handle_str(char *arg, int *argc)
{
	char	**split_args;
	int		i;

	split_args = ft_split(arg, ' ');
	if (!split_args)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (split_args[i])
		i++;
	*argc = i;
	return (split_args);
}

