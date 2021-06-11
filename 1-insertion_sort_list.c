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
    listint_t *h = *list, *h2 = NULL;
    int tmp, tmp2;

    while(h->next)
    {
        h2 = h;
        if (h->next->n < h->n)
        {
            tmp = h->n;
            h->n = h->next->n;
            h->next->n = tmp;

            while(h2->prev && h2->prev->n > h2->n)
            {
                tmp2 = h2->n;
                h2->n = h2->prev->n;
                h2->prev->n = tmp2;
                /* move to the previous position in the list */
                h2 = h2->prev;
            }
        }
        h = h->next;
    }
}