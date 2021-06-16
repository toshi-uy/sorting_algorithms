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
	int j, k, size_i = 0, *index, *aux, biggest = 0, count = 0;

	for (i = 0; i < size; i++)
	{
		if (biggest < array[i])
			biggest = array[i];
	}
	aux = malloc(sizeof(int) * (biggest + 1));
	index = malloc(sizeof(int) * (biggest + 1));

	for (i = 0; i < biggest; i++)
		aux[i] = 0;
	for (j = 0; j <= biggest; j++)
	{
		size_i += 1;
		for (i = 0; i < size; i++)
		{
			if (array[i] == j)
			{
				count += 1;
			}
		}
		aux[j] = count;
	}
	print_array(aux, size_i);
	for (k = 1; k < size_i; k++)
	{
		if (index[k] < index[k + 1])
			array[index[k]] = k + 1;
	}
	free(index);
}
