#include "sort.h"
#include "swap.c"

/**
 * counting_sort - this is the Counting sort algorithm
 * implementation in C
 * @array: array of integers
 * @size: size of array
 * Return: no-return (void function)
 */

void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int j, k, size_i = 0, *index, biggest = 0, count = 0;

	for (i = 0; i < size; i++)
	{
		if (biggest < array[i])
			biggest = array[i];
	}
	index = malloc(sizeof(int) * (biggest + 1));

	for (j = 0; j <= biggest; j++)
	{
		size_i += 1;
		for (i = 0; i < size; i++)
		{
			if (array[i] == j)
			{
				count += 1;
				break;
			}
		}
		index[j] = count;
	}
	print_array(index, size_i);
	for (k = 0; k < size_i - 1; k++)
	{
		if (index[k] < index[k + 1])
			array[index[k]] = k;
	}
	free(index);
}
