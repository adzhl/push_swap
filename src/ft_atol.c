/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:45:12 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/13 10:13:52 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *str)
{
	int		negative;
	long	result;

	negative = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		negative = negative * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * negative);
}

/* int main(void)
{
	const char *test_strings[] = {
		"12345",          // Positive number
		"-12345",         // Negative number
		"   12345",       // Number with leading spaces
		"   -12345",      // Negative number with leading spaces
		"+12345",         // Number with explicit positive sign
		"42",             // Simple number
		"   0",           // Number with spaces and zero
		"    +0",         // Explicitly positive zero
		"  -000123",      // Leading zeros with negative sign
		"123abc",         // Number with trailing non-numeric characters
		"abc123",         // Non-numeric characters before number
		""                // Empty string
	};

	size_t num_tests = sizeof(test_strings) / sizeof(test_strings[0]);
	size_t i;
	long ft_result;
	long atol_result;

	for (i = 0; i < num_tests; i++)
	{
		ft_result = ft_atol(test_strings[i]);
		atol_result = atol(test_strings[i]);
		printf("Input: \"%s\"\n", test_strings[i]);
		printf("ft_atol Result: %ld\n", ft_result);
		printf("atol Result: %ld\n", atol_result);
		printf("\n");
	}

	return (0);
} */
