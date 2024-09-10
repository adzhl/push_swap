/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:14:28 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/15 17:38:48 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

int main(void)
{
    const char *test_strings[] = {
        "  +123abc",   // Expect 123 with endptr pointing to 'abc'
        "  -00123",    // Expect -123 with endptr pointing to NULL
        "   0x1F",     // Expect 31 with endptr pointing to NULL (base 16)
        "42",          // Expect 42 with endptr pointing to NULL
        "   1e10",     // Expect 1 with endptr pointing to 'e10'
        "  1000x",     // Expect 1000 with endptr pointing to 'x'
        "12345abc",    // Expect 12345 with endptr pointing to 'abc'
    };
    int bases[] = {10, 10, 16, 10, 10, 10, 10};
    size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);
    size_t i;
    char *endptr;
    long result;

    for (i = 0; i < num_tests; i++)
    {
        result = strtol(test_strings[i], &endptr, bases[i]);
        printf("Input: \"%s\"\n", test_strings[i]);
        printf("Base: %d\n", bases[i]);
        printf("Result: %ld\n", result);
        printf("Endptr points to: \"%s\"\n\n", endptr);
    }

    return 0;
}
