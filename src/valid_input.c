/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:42:39 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/15 18:02:18 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int valid_int(char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    if (*str == '\0')
        return (0);
    if (*str == '0' && *(str + 1) != '\0')
        return (0);
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0);
        str++;
    }
    return (1);
}

static int check_dup(int *num, int count, int value)
{
    int i;

    i = 0;
    while (i < count)
    {
        if (num[i] == value)
            return (1);
        i++;
    }
    return (0);
}

int valid_input(int argc, char **argv)
{
    int i;
    long nbr;
    int num[argc - 1];
    int num_count;

    num_count = 0;
    i = 1;
    while (i < argc)
    {
        if (!valid_int(argv[i]))
            return (0);
        nbr = ft_atol(argv[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
            return (0);
        if (check_dup(num, num_count, (int)nbr))
            return (0);
        num[num_count++] = (int)nbr;
        i++;
    }
    return (1);
}

/* int main(int argc, char **argv)
{
    // Test cases
    int result = valid_input(argc, argv);

    if (result)
        printf("Valid input.\n");
    else
        printf("Invalid input.\n");

    return 0;
} */
