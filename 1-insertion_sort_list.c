#include "sort.h"
#include "swap.c"

/**
 * insertion_sort_list - this is the Bubble sort algorithm implementation in C
 * @list: pointer to list
 * Return: no-return (void function)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *h = NULL, *h2 = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	h = *list;
	while (h)
	{
		if (h->next->n < h->n)
		{
			swap_forward(h);
			print_list(*list);
			h2 = h->prev;
			while (h2->prev && h2->n < h2->prev->n)
			{
				swap_back(h2, list);
				print_list(*list);
			}
		}
		else
			h = h->next;
	}
}
