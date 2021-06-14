#include"sort.h"
#ifndef PRINT_LIST
#define PRINT_LIST
#include "print_list.c"
#endif
#ifndef PRINT_ARRAY
#define PRINT_ARRAY
#include "print_array.c"
#endif

/**
 * swap - swap to integers in an array
 * @array: the array to be sorted
 * @pos1: position of integer to swap
 * @pos2: position of integer to swap
 */

void swap(int *array, int pos1, int pos2)
{
	int tmp;

	tmp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = tmp;
}

/**
 * swap_forward - swap nodes with next in double linked list 
 * @head: pointer to head of list
 * @list: pointer to pointer of list
 */

void swap_forward(listint_t *head, listint_t **list)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	tmp1 = head;
	if (head->next)
		tmp2 = head->next;
	if (tmp1->prev)
		tmp1->prev->next = tmp2;
	if (tmp2 && tmp2->next)
		tmp2->next->prev = tmp1;
	tmp1->next = tmp2->next;
	tmp2->prev = tmp1->prev;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	print_list(*list);
}

/**
 * swap_forward - swap nodes with next in double linked list 
 * @head: pointer to head of list
 * @list: pointer to pointer of list
 */

void swap_back(listint_t *head, listint_t **list)
{
	listint_t *tmp1 = NULL, *tmp2 = NULL;

	tmp2 = head->prev;
	tmp1 = head;
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
