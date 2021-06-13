#include "sort.h"
#include "swap.c"

/**
 * selection_sort - this is the Selection sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void quick_sort(int *array, size_t size)
{
	int lo = 0, hi = size - 1;

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

int lom_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i = lo, j = lo;
	

	for (j; j <= size - 1;)
	{
		if (array[j] < pivot)
		{
			swap(array, j, i);
			print_array(array, size);
			i++;
		}
		j++;
	}
	swap(array, (i + 1), hi);
	print_array(array, size);
	return(i + 1);
}
