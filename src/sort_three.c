/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:58:48 by abinti-a          #+#    #+#             */
/*   Updated: 2024/09/22 17:49:33 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	case1(t_stack **a, int middle, int bottom)
{
	if (middle > bottom)
	{
		ra(a);
		sa(a);
	}
	else
		ra(a);
}

static void	case2(t_stack **a, int top, int bottom)
{
	if (top > bottom)
		rra(a);
	else
	{
		rra(a);
		sa(a);
	}
}

static void	case3(t_stack **a, int top, int middle)
{
	if (top > middle)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	top = (*a)->num;
	middle = (*a)->next->num;
	bottom = (*a)->next->next->num;
	if (top > middle && top > bottom)
		case1(a, middle, bottom);
	else if (middle > top && middle > bottom)
		case2(a, top, bottom);
	else if (bottom > top && bottom > middle)
		case3(a, top, middle);
}
