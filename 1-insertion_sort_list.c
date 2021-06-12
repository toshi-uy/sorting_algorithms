#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - this is the Bubble sort algorithm implementation in C
 * @list: pointer to list
 * Return: no-return (void function)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *h = NULL, *h2 = NULL, *tmp1 = NULL, *tmp2 = NULL;

	h = *list;
	while(h->next)
	{
		h2 = h;
		if(h->next)
		{
			if (h->next->n < h->n)
			{
				tmp1 = h;
				if (tmp1->prev)
					tmp1->prev->next = tmp1->next;
				if (tmp1->next->next)
					tmp1->next->next->prev = tmp1;

				tmp1->next->prev = tmp1->prev;
				tmp1->prev = tmp1->next;
				if (tmp1->next->next)
					tmp2 = tmp1->next->next;
				tmp1->next->next = tmp1;
				tmp1->next = tmp2;

				while(h2->prev && h2->prev->n > h2->n)
				{
					tmp1 = h2;
					if (tmp1->prev)
						tmp1->prev->next = tmp1->next;
					if (tmp1->next->next)
						tmp1->next->next->prev = tmp1;

					tmp1->next->prev = tmp1->prev;
					tmp1->prev = tmp1->next;
					if (tmp1->next->next)
						tmp2 = tmp1->next->next;
					tmp1->next->next = tmp1;
					tmp1->next = tmp2;

					h2 = h2->prev;
			
				}
			}
			h = h->next;
		}
	}
}

/**
 * 
 * tmp1 = h2
 * 
 * if(h2->next)
 *      tmp2 = h2->next
 * 
 * 
 * if(tmp1->prev)
 *      tmp1->prev->next = tmp2
 * if(tmp2->next)
 *      tmp2->next->prev = tmp1
 * 
 * tmp1->prev = tmp2
 * tmp1->next = tmp2->next
 * 
 * tmp2->prev = tmp1->prev
 * tmp2->next = tmp1
 * 
 * 
 */