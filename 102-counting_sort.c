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
	int j, k, *index, biggest = 0, count = 0;

	for (i = 0; i < size; i++)
	{
		if (biggest < array[i])
			biggest = array[i];
	}
	biggest += 1;
	index = malloc(sizeof(int) * (biggest + 1));

	for (j = 0; j <= biggest; j++)
		index[j] = 0;
	for (j = 0; j <= biggest; j++)
	{
		count = 0;
		for (i = 0; i < size; i++)
		{
			if (array[i] == j)
			{
				count += 1;
			}
		}
		index[j] = count;
	}
	print_array(index, biggest);
	printf("\n");
	for (j = 1; j <= biggest; j++)
	{
		index[j] += index[j - 1];
	}
	print_array(index, biggest);
	/*for (k = 1; k < size_i; k++)
	{
		if (aux[k] < aux[k + 1])
			array[aux[k]] = k + 1;
	}*/
	free(index);
}
