#include "sort.h"
#include "swap.c"

/**
 * recursive_func_forward - this is the Cocktail sort algorithm implementation in C
 * @list: pointer to list
 * @min: min node 
 * @max: 
 * Return: no-return (void function)
 */

void recursive_func_forward(listint_t *min, listint_t *max, listint_t **list)
{
	listint_t *h = min;
	int no_swap = 0;

	while(h->next != max)
	{
		if (h->n > h->next->n)
		{
			swap_forward(h, list);
			no_swap = 0;
		}
		else
		{
			no_swap = 1;
			h = h->next;
		}
	}
	if (no_swap == 1 && h->next == max)
		return;
	h->prev = max;
	recursive_func_back(min, max, list);
}

/**
 * recursive_func_back - this is the Cocktail sort algorithm implementation in C
 * @list: pointer to list
 * Return: no-return (void function)
 */

void recursive_func_back(listint_t *min, listint_t *max, listint_t **list)
{
	listint_t *h = min;
	int no_swap = 0;

	while (h->prev)
	{
		if (h->n > h->prev->n)
		{
			swap_back(h, list);
			no_swap = 0;
		}
		else
		{
			no_swap = 1;
			h = h->prev;
		}	
	}
	if (no_swap == 1 && h->prev == min)
		return;
	h->next = min;
	recursive_func_forward(min, max, list);
}
/**
 * cocktail_sort_list - this is the Cocktail sort algorithm implementation in C
 * @list: pointer to list
 * Return: no-return (void function)
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *h = NULL, *max = NULL, *min = NULL;
	int no_swap = 0;

	if (!list || !(*list) || !(*list)->next)
		return;
	h = *list;
	while(h->next)
	{
		if (h->n > h->next->n)
		{
			swap_forward(h, list);
			no_swap = 0;
		}
		else
		{
			no_swap = 1;
			h = h->next;
		}
	}
	min = *list;
	if (!h->next && h->prev)
	{
		max = h->prev;
		h = max;
	}
	if (no_swap == 1 && h->next == NULL)
		return;

	recursive_func_back(min, max, list);
}
