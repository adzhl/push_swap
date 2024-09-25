/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:52:08 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/24 10:17:55 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/get_next_line.h"
# include "push_swap.h"

// utils
void	execute_instruction(t_stack **a, t_stack **b, char *instruction);
void	process_instructions(t_stack **a, t_stack **b);

#endif