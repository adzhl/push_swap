/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:00:52 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/28 17:05:55 by abinti-a         ###   ########.fr       */
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
    int     num;
    int     index;
    int     above_median;
    int     size;
    struct s_stack *target;
    struct s_stack *next;
    struct s_stack *prev;
}               t_stack;

typedef struct s_move
{
    int         cost;
    t_stack     *cheapest;
}               t_move;

//handle string
char **handle_str(char *arg, int *new_argc);

//valid input
int valid_input(int argc, char **argv);

//initialization
t_stack *initialize_stack(int argc, char **argv, t_stack **a);

//sorting
void sort_three(t_stack **a);
void sort_stacks(t_stack **a, t_stack **b);

//find cost
void calculate_cost(t_stack *a, t_stack *b, t_move *move);
void find_cheapest(t_stack *a, t_stack *b, t_move *move);
void execute_cheapest(t_stack **a, t_stack **b, t_move *move);

//operations
void push(t_stack **dst, t_stack **src);
void swap(t_stack **stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);

//specific operations
void push_a(t_stack **a, t_stack **b);
void push_b(t_stack **a, t_stack **b);
void swap_a(t_stack **a);
void swap_b(t_stack **b);
void rotate_a(t_stack **a);
void rotate_b(t_stack **b);
void rr_a(t_stack **a);
void rr_b(t_stack **b);

//analyze stack
/* int get_min(t_stack *stack);
int get_max(t_stack *stack);
int get_index(t_stack *stack, int value); */

//utils
long	ft_atol(const char *str);
int stack_size(t_stack *stack);
int is_above_median(t_stack *stack, t_stack *node);
void set_target(t_stack *a, t_stack *b);
int is_sorted(t_stack *stack);

//cleanup
int handle_error(char **split_args, t_stack *a, t_stack *b);
void cleanup(t_stack *a, t_stack *b, char **split_args);

#endif