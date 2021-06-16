#include "sort.h"
#include "swap.c"

/**
 * recursive_func_forward - this is the Cocktail sort algorithm
 * implementation in C
 * @list: pointer to list
 * @min: min node value of the list
 * @max: mmax value of the list
 * Return: no-return (void function)
 */

void recursive_func_forward(listint_t *min, listint_t *max, listint_t **list)
{
	listint_t *h = NULL;
	int no_swap = 1;

	h = min;
	while (h != max)
	{
		if (h->n > h->next->n)
		{
			if (h->next == max)
			{
				swap_forward(h, &*list);
				print_list(*list);
				no_swap = 0;
				break;
			}
			else
			{
				swap_forward(h, &*list);
				print_list(*list);
				no_swap = 0;
			}
		}
		else
		{
			no_swap = 1;
			h = h->next;
		}
	}
	if (no_swap == 1 && h == max->prev)
		return;
	max = h->prev;
	recursive_func_back(min, max, list);
}

/**
 * recursive_func_back - this is the Cocktail sort algorithm
 * implementation in C
 * @list: pointer to list
 * @min: min node value of the list
 * @max: mmax value of the list
 * Return: no-return (void function)
 */

void recursive_func_back(listint_t *min, listint_t *max, listint_t **list)
{
	listint_t *h;
	int no_swap = 1;

	h = max;
	while (h != min)
	{
		if (h->n < h->prev->n)
		{
			if (h->prev == min)
			{
				swap_back(h, &*list);
				print_list(*list);
				no_swap = 0;
				break;
			}
			else
			{
				swap_back(h, &*list);
				print_list(*list);
				no_swap = 0;
			}
		}
		else
		{
			no_swap = 1;
			h = h->prev;
		}
	}
	if (no_swap == 1 && h == min)
		return;
	min = h->next;
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
	int no_swap = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	h = *list;
	while (h->next)
	{
		if (h->n > h->next->n)
		{
			swap_forward(h, &*list);
			print_list(*list);
			no_swap = 0;
		}
		else
		{
			no_swap = 1;
			h = h->next;
		}
	}
	min = *list;
	if (!h->next)
	{
		max = h;
	}
	if (no_swap == 1 && h->next == NULL)
		return;

	recursive_func_back(min, max, list);
}
