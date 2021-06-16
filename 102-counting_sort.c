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
	biggest += 2;
	index = malloc(sizeof(int) * biggest);

	for (j = 0; j < biggest; j++)
		index[j] = 0;
	for (j = 0; j < biggest; j++)
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
	printf("\n");
	for (j = 1; j < biggest; j++)
	{
		index[j] += index[j - 1];
	}
	print_array(index, biggest);
	for (k = biggest - 1; k > 0; k--)
	{
		if (index[k] > index[k - 1])
			while(index[k] - index[k - 1] >= 1)
			{
				array[index[k] - 1] = k;
				index[k] -= 1;
			}
	}
	free(index);
}
