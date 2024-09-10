/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abinti-a <abinti-a@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 21:42:08 by abinti-a          #+#    #+#             */
/*   Updated: 2024/08/14 22:26:38 by abinti-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push_min_to_b(t_stack *a, t_stack *b)  
{  
     int min;

    (void)b;
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

int get_median(t_stack *s, int size)  
{  
    int *temp = malloc(sizeof(int) * size);  
    for (int i = 0; i < size; i++)  
        temp[i] = s->array[s->top - i];  
    
    // Simple bubble sort to find median  
    for (int i = 0; i < size - 1; i++)  
        for (int j = 0; j < size - i - 1; j++)  
            if (temp[j] > temp[j + 1])  
            {  
                int t = temp[j];  
                temp[j] = temp[j + 1];  
                temp[j + 1] = t;  
            }  
    
    int median = temp[size / 2];  
    free(temp);  
    return median;  
}  

void quicksort(t_stack *a, t_stack *b, int size)  
{  
    if (size <= 3)  
    {  
        if (size == 3)  
        {  
            sort_three(a);  
        }  
        else if (size == 2 && a->array[a->top] > a->array[a->top - 1])  
        {  
            swap_a(a);  
        }  
        return;  
    }  

    int pivot = a->array[a->top - size / 2];  // Choose middle element as pivot  
    int i = 0;  
    int pushed = 0;  

    while (i < size)  
    {  
        if (a->array[a->top] < pivot)  
        {  
            push_b(a, b);  
            pushed++;  
        }  
        else  
        {  
            rotate_a(a);  
        }  
        i++;  
    }  

    // Undo rotations  
    for (int j = 0; j < size - pushed; j++)  
    {  
        rr_a(a);  
    }  

    // Recursively sort the partitions  
    quicksort(a, b, size - pushed);  
    
    // Move elements back to A and sort  
    for (int j = 0; j < pushed; j++)  
    {  
        push_a(a, b);  
    }  
    quicksort(a, b, pushed);  
} 

/* void turk_sort_part(t_stack *a, int gap, int i)
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
} */