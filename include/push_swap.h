/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:00:52 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/21 15:46:16 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				num;
	int				index;
	int				above_median;
	int				cost;
	bool	cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// handle string
char				**handle_str(char *arg, int *argc);

// valid input
int					valid_input(int argc, char **argv, t_stack **a);

// initialization
// void				initialize_stack(char **argv, t_stack **a);
void				append_node(t_stack **stack, int num);

// sorting
void				sort_three(t_stack **a);
void				sort_stacks(t_stack **a, t_stack **b);
void sort_small(t_stack **a, t_stack **b);
void sort_big(t_stack **a, t_stack **b);

//target
void target_for_a(t_stack *a, t_stack *b);
void target_for_b(t_stack *a, t_stack *b);

//cost
void find_cost_a(t_stack *a, t_stack *b);
void cheapest_cost(t_stack *stack);
t_stack *get_cheapest(t_stack *stack);

// operations
void				push(t_stack **dst, t_stack **src);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

// specific operations
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				swap_a(t_stack **a);
void				swap_b(t_stack **b);
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **b);
void				rotate_ab(t_stack **a, t_stack **b);
void				rr_a(t_stack **a);
void				rr_b(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// utils
long				ft_atol(const char *str);
int					stack_size(t_stack *stack);
int					is_sorted(t_stack *stack);
void				current_index(t_stack **stack);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_largest(t_stack *stack);

void prepare_stack_a(t_stack **a, t_stack **b);
void    rotate_to_top(t_stack **stack, t_stack *top, char stack_name);
void min_to_top(t_stack **a);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// cleanup
int					handle_error(char **split_args, t_stack *a, t_stack *b);
void				cleanup(t_stack *a, t_stack *b, char **split_args);

void prepare_stack_b(t_stack **a, t_stack **b);
void	rr_both_b(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rrr_both_b(t_stack **a, t_stack **b, t_stack *cheapest_node);
void find_cost_b(t_stack *a, t_stack *b);

#endif