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
	listint_t *h = NULL, *h2 = NULL, *tmp1 = NULL, *tmp2 = NULL;

	h = *list;

	while(h->next)
	{
		h2 = h;
		if (h->next->n < h->n)
		{
			tmp1 = h;
			if(h->next)
				printf("entro 1")
				tmp2 = h->next;
			
			if(tmp1->prev)
				printf("entro2")
				tmp1->prev->next = tmp2;
			if(tmp2->next)
				printf("entro 3")
				tmp2->next->prev = tmp1;
			printf("cambiando tmp2 y tmp1")
			tmp2->prev = tmp1->prev;
			tmp1->next = tmp2->next;
			
			printf("cambiando prev y next")
			tmp1->prev = tmp2;
			tmp2->next = tmp1;

			while(h2->prev && h2->prev->n > h2->n)
			{
				tmp1 = h2;
				
				printf("entro al while")
				if(h2->next)
					printf("entro 4")
					tmp2 = h2->next;
				
				if(tmp1->prev)
					printf("entro 5")
					tmp1->prev->next = tmp2;
				if(tmp2->next)
					printf("entro 6")
					tmp2->next->prev = tmp1;
				
				tmp2->prev = tmp1->prev;
				tmp1->next = tmp2->next;
				
				tmp1->prev = tmp2;
				tmp2->next = tmp1;

				h2 = h2->prev;
			}
		}
	h = h->next;
	}
}


/**
 * 
 * tmp1 = h2
 * 
 * if(h2->next)
 *      tmp2 = h2->next
 * 
 * if(tmp1->prev)
 *      tmp1->prev->next = tmp2
 * if(tmp2->next)
 *      tmp2->next->prev = tmp1
 * 
 * tmp2->prev = tmp1->prev
 * tmp1->next = tmp2->next
 * 
 * tmp1->prev = tmp2
 * tmp2->next = tmp1
 * 
 * 
 */