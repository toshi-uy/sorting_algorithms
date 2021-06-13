#include "sort.h"

/**
 * selection_sort - this is the Selection sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void selection_sort(int *array, size_t size)
{
	size_t min = 0, tmp = 0, i = 0, j = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
			if (min != i)
			{
				tmp = array[min];
				array[min] = array[i];
				array[i] = tmp;
				print_array(array, size);ç
			}
	}
}
