/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:00:52 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/25 10:55:43 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				above_median;
	int				cost;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// process arguments
char				**process_arguments(int *argc, char ***argv, int *new_argc);

// handle string
char				**handle_str(char *arg, int *argc);

// valid input
int					valid_int(char *str);
int					valid_input(int argc, char **argv, t_stack **a);

// initialization
void				append_node(t_stack **stack, int num);

// sorting
void				sort_three(t_stack **a);
void				sort_stacks(t_stack **a, t_stack **b);
void				sort_small(t_stack **a, t_stack **b);
void				sort_big(t_stack **a, t_stack **b);

// target
void				target_for_b(t_stack *a, t_stack *b);

// cost
void				find_cost_b(t_stack *a, t_stack *b);
void				cheapest_cost(t_stack *stack);
t_stack				*get_cheapest(t_stack *stack);

// operations
void				push(t_stack **dst, t_stack **src);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

// specific operations
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **a, t_stack **b, int print);
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b, int print);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b, int print);

// utils
long				ft_atol(const char *str);
int					stack_size(t_stack *stack);
int					is_sorted(t_stack *stack);
void				current_index(t_stack **stack);
t_stack				*find_smallest(t_stack *stack);
t_stack				*find_largest(t_stack *stack);

// sort big utils
void				rotate_to_top(t_stack **stack, t_stack *top,
						char stack_name);
void				rr_both_b(t_stack **a, t_stack **b, t_stack *cheapest_node);
void				rrr_both_b(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				min_to_top(t_stack **a);

int					get_mean(t_stack *stack);
void				push_b_to_a(t_stack **a, t_stack **b);
void				set_cheapest_cost(t_stack **a, t_stack **b);

// error handling
void				free_stack(t_stack *stack);
int					handle_error(t_stack *a, t_stack *b, char **split_args);
void				cleanup(t_stack *a, t_stack *b, char **split_args);

#endif