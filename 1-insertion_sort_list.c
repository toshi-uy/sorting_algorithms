#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - this is the Bubble sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *h = *list, *h2 = NULL, *tmp1 = NULL, *tmp2 = NULL;

    while(h->next)
    {
        h2 = h;
        if (h->next->n < h->n)
        {
            tmp1 = h;
            tmp1->next = tmp1->next->next;
            tmp1->next->prev = tmp1->prev;
            tmp1->next->next = tmp1;
            tmp1->prev = tmp1->next;

            while(h2->prev && h2->prev->n > h2->n)
            {
                tmp2 = h2;
                tmp2->next = tmp2->next->next;
                tmp2->next->prev = tmp2->prev;
                tmp2->next->next = tmp2;
                tmp2->prev = tmp2->next;

                h2 = h2->prev;
            }
        }
        h = h->next;
    }
}