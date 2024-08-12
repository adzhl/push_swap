/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:14:28 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 19:49:41 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int invalid_input(const char *str)
{
    if (*str == '\0')
        return (1);
    if ((*str == '-' || *str == '+') && *(str + 1) == '\0')
        return (1);
    return (0);
}

const char *skip_space(const char *str)
{
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    return (str);
}

int parse_sign(const char **str)
{
    int sign;

    sign = 1;
    if (**str == '-' || **str == '+')
    {
        if (**str == '-')
            sign = -1;
        (*str)++;
    }
    return (sign);
}

int char_to_digit(char c, int base) 
{
    int digit;

    digit = 0;
    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'a' && c <= 'z')
        digit = c - 'a' + 10;
    else if (c >= 'A' && c <= 'Z')
        digit = c - 'A' + 10;
    if (digit < base) 
        return (digit);
    return (-1);
}

long ft_strtol(const char *str, char **endptr, int base)
{
    long result;
    int sign;
    int digit;

    result = 0;
    str = skip_space(str);
    sign = parse_sign(&str);
    while (*str)
    {
        digit = char_to_digit(*str, base);
        if (digit == -1)
            break ;
        result = result * base + digit;
        str++;
    }
    if (endptr)
        *endptr = (char *)str;
    return (sign * result);
}
