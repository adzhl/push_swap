/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:00:52 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 21:57:11 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
    int *array;
    int size;
    int top;
} t_stack;

// Function prototypes
void parse_arg(int argc, char **argv, t_stack *stack_a);

//sorting
void sort_three(t_stack *a);  
void push_min_to_b(t_stack *a, t_stack *b);  
void sort_small(t_stack *a, t_stack *b);  
void turk_sort_part(t_stack *a, int gap, int i);  
void turk_sort(t_stack *a, t_stack *b);  
void optimize_stack(t_stack *a);  
void sort_stack(t_stack *a, t_stack *b);

//operations
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void reverse_rotate(t_stack *stack);

//specific operations
void push_a(t_stack *a, t_stack *b);
void push_b(t_stack *a, t_stack *b);
void swap_a(t_stack *a);
void swap_b(t_stack *b);
void rotate_a(t_stack *a);
void rotate_b(t_stack *b);
void rr_a(t_stack *a);
void rr_b(t_stack *b);

//utils
int get_min(t_stack *stack);
int get_max(t_stack *stack);
int get_index(t_stack *stack, int value);
int isqrt(int n);
int valid_int(const char *str);
int invalid_input(const char *str);
long ft_strtol(const char *str, char **endptr, int base);
void param(int closest_index, t_stack *a);

#endif