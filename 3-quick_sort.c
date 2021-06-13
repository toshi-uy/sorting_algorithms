#include "sort.h"
#include "swap.c"

/**
 * quick_sort - this is the Quick sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void quick_sort(int *array, size_t size)
{
	int lo = 0, hi = (size - 1);

	lomuto_sort(array, lo, hi, size);
}

/**
 * lomuto_sort - Lomuto sorting alog
 * @array: array of ints
 * @size: size of array
 * @lo: lower value
 * @hi: highter value
 * Return: no-return (void function)
 */

void lomuto_sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lom_partition(array, lo, hi, size);
		lomuto_sort(array, lo, p - 1, size);
		lomuto_sort(array, p + 1, hi, size);
	}
}

/**
 * lom_partition - Lomuto sorting partition
 * @array: array of ints
 * @size: size of array
 * @lo: lower value
 * @hi: highter value
 * Return: no-return (void function)
 */

int lom_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo, j = lo;

	for (; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, j, i);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(array, i, hi);
	if (array[hi] != pivot)
		print_array(array, size);
	return (i);
}
