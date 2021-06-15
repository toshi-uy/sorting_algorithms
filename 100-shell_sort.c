#include "sort.h"
#include "swap.c"

/**
 * insertion - this is the insertion sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void insertion(int *array, size_t size)
{
	size_t i = 0, j = 0;

	for (; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			swap(array, i, i + 1);
			j = i;
			while (j > 0 && array[j] < array[j - 1])
			{
				swap(array, j, j - 1);
				j--;
			}
		}
	}
}

/**
 * shell_sort - this is the Shell sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0;

	while (gap < size / 3)
		gap = (gap * 3) + 1;
	while (gap > 0)
	{
		if (gap != 1)
		{
			while (i < size - 1 && (i + gap) != size)
			{
				if (array[i] > array[i + gap])
				{
					swap(array, i + gap, i);
				}
				i++;
			}
		}
		else
			insertion(array, size);
		print_array(array, size);
		gap /= 3;
	}
}
