/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 21:00:57 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 21:35:00 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int isqrt(int n)
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
}

int valid_int(const char *str)
{
    if (*str == '-' || *str == '+')
        str++;
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