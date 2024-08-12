/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:06:07 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 21:56:37 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void optimize_stack(t_stack *a)  
{  
    int min;
    int min_index;
    
    min = get_min(a);  
    min_index = get_index(a, min);  
    while (a->array[a->top] != min)  
    {  
        if (min_index > a->top / 2)  
            rotate_a(a);  
        else  
            rr_a(a);  
    }  
}  

void sort_stack(t_stack *a, t_stack *b)  
{  
    if (a->size <= 3)  
        sort_three(a);  
    else if (a->size <= 5)  
        sort_small(a, b);  
    else  
    {  
        turk_sort(a, b);  
        optimize_stack(a);  
    }  
} 
