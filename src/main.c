/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:14:47 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/15 16:33:07 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void handle_sort(t_stack *a, t_stack *b)
{
    if(!is_sorted(a))
    {
        if (a->size == 2)
            swap_a(&a);
        else if (a->size == 3)
            sort_three(&a);
        else
            sort_stacks(&a, &b);
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    char **split_args;

    a = NULL;
    b = NULL;
    split_args = NULL;
    if (argc < 2 || (argc == 2 && !argv[1][0]))
        return (0);
    if (argc == 2)
    {
        split_args = handle_str(argv[1], &argc);
        argv = split_args;
    }
    if (!valid_input(argc, argv))
        handle_error(split_args, a, b);
    a = initialize_stack(argc, argv, &a);
    if (!a)
        handle_error(split_args, a, b);
    handle_sort(a, b);
    cleanup(a, b, split_args);
    return (0);
}
