#include "sort.h"

/**
 * selection_sort - this is the Selection sort algorithm implementation in C
 * @array: array of ints
 * @size: size of array
 * Return: no-return (void function)
 */

void selection_sort(int *array, size_t size)
{
    int max = 0, tmp = 0;
    size_t i = 0, j = 0, size2 = size;

    for (i = 0; i < size - 1; i++)
    {
        max = 0;
        for (j = 0; j < size2; j++)
        {
            if (array[j] > array[max])
                max = j;
        }

        tmp = array[max];
        array[max] = array[j - 1];
        array[j -1] = tmp;
        print_array(array, size);
        size2 -= 1;
    }
}