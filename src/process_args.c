/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:00:55 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 12:04:13 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	count_total_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		total_count;
	char	**temp;

	total_count = 0;
	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			handle_error(NULL, NULL, NULL);
		temp = handle_str(argv[i], &j);
		total_count += j;
		k = 0;
		while (k < j)
		{
			free(temp[k]);
			k++;
		}
		free(temp);
		i++;
	}
	return (total_count);
}

static void	fill_split_args(char **split_args, int argc, char **argv,
		int *count)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = 1;
	*count = 0;
	while (i < argc)
	{
		temp = handle_str(argv[i], &j);
		k = 0;
		while (k < j)
		{
			split_args[*count] = temp[k];
			(*count)++;
			k++;
		}
		free(temp);
		i++;
	}
	split_args[*count] = NULL;
}

char	**process_arguments(int *argc, char ***argv, int *new_argc)
{
	char	**split_args;
	int		total_count;

	if (*argc < 2)
		return (NULL);
	total_count = count_total_args(*argc, *argv);
	split_args = malloc((total_count + 1) * sizeof(char *));
	if (!split_args)
		handle_error(NULL, NULL, split_args);
	fill_split_args(split_args, *argc, *argv, new_argc);
	*argv = split_args;
	return (split_args);
}
