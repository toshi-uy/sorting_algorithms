#include "sort.h"

/**
 * insertion_sort_list - this is the Bubble sort algorithm implementation in C
 * @list: pointer to list
 * Return: no-return (void function)
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *h = *list, *h2 = NULL, *tmp1 = NULL, *tmp2 = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (h->next)
	{
		if (h->next->n < h->n)
		{
			tmp1 = h;
			if (h->next)
				tmp2 = h->next;
			if (tmp1->prev)
				tmp1->prev->next = tmp2;
			if (tmp2 && tmp2->next)
				tmp2->next->prev = tmp1;
			tmp1->next = tmp2->next;
			tmp2->prev = tmp1->prev;
			tmp1->prev = tmp2;
			tmp2->next = tmp1;
			print_list(*list);
			h2 = h->prev;
			while (h2->prev && h2->n < h2->prev->n)
			{
				tmp2 = h2->prev;
				tmp1 = h2;
				if (tmp2->prev)
					tmp2->prev->next = tmp1;
				tmp1->next->prev = tmp2;
				tmp2->next = tmp1->next;
				tmp1->prev = tmp2->prev;
				tmp2->prev = tmp1;
				tmp1->next = tmp2;
				if (!tmp1->prev)
					*list = tmp1;
				print_list(*list);
			}
		}
		else
			h = h->next;
	}
}
