/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:14:47 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 16:32:00 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    if (argc < 2)
        return (0);
    parse_arg(argc, argv, &stack_a);
    stack_b.array = malloc(sizeof(int) * stack_a.size);
    stack_b.size = stack_a.size;
    stack_b.top = -1;
    sort_stack(&stack_a, &stack_b);
    free(stack_a.array);
    free(stack_b.array);
    return (0);
}