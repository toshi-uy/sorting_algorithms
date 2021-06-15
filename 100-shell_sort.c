#include "sort.h"
#include "swap.c"

/**
 * shell_sort - this is the Shell sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0, j = 0, k = 0;

	if (!array || size < 2)
		return;
	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap > 0)
	{
		for (i = 0; i < gap; i++)
		{
			j = i;
			while ((j + gap) <= size - 1)
			{
				if (array[j] > array[j + gap])
				{
					swap(array, j, j + gap);
					k = j;
					while (array[k] < array[k - gap])
					{
						swap(array, k, k - gap);
						k -= gap;
					}
				}
				j += gap;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
