/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 21:42:08 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/12 22:02:51 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three(t_stack *a)
{
    int top;
    int middle;
    int bottom;

    top = a->array[a->top];
    middle = a->array[a->top - 1];
    bottom = a->array[a->top - 2];
    if (a->top < 2)
        return;
    if (top > middle && top > bottom)
    {
        rotate_a(a);
        if (top > middle)
            swap_a(a);
    }
    else if (top > middle)
        swap_a(a);
    else if (middle > bottom)
    {
        rr_a(a);
        if (top > middle)
            swap_a(a);
    }
}

void push_min_to_b(t_stack *a, t_stack *b)  
{  
    int min;
    
    min = get_min(a);  
    while (a->array[a->top] != min)  
    {  
        if (get_index(a, min) > a->top / 2)  
            rotate_a(a);  
        else  
            rr_a(a);  
    }  
}

void sort_small(t_stack *a, t_stack *b)
{
    while (a->top > 2)  
        push_min_to_b(a, b);  
    sort_three(a);  
    while (b->top >= 0)  
        push_a(a, b); 
}

void turk_sort_part(t_stack *a, int gap, int i)
{
    int j;
    int k;

    j = i + gap;
    while (j <= a->top)
    {
        if (a->array[i] > a->array[j])
        {
            while (j > i)
            {
                swap_a(a);
                rotate_a(a);
                j--;
            }
            k = 0;
            while (k < gap)
            {
                rr_a(a);
                k++;
            }
        }
        j += gap;
    }
}

void turk_sort(t_stack *a, t_stack *b)
{
    int gap;
    int i;

    gap = a->size;
    while (gap > 1)
    {
        gap = gap * 10 / 13;
        if (gap == 9 || gap == 10)
            gap = 11;
        if (gap < 1)
            gap = 1;
        i = 0;
        while (i + gap <= a->top)
        {
            turk_sort_part(a, gap, i);
            i++;
        }
    }
    (void)b;
}