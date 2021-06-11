#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * Bubble-sort - this is the Bubble sort algorithm implementation in C
 *
 * Return: no-return (void function)
 */

void bubble_sort(int *array, size_t size)
{
    size_t i = 0, j = 0;
    int tmp;

    /* loop over the array size times */
    for (i = 0; i < size; i++)
    {
        /**
         * loop over two elements to swap the values
         * Move the biggest to the second position of the bubble
         * The biggest element will move to the last position because
         * it will be always the gratest value in a bubble of two
         * 
         * When the the loop gets two the end condition i will increment
         * and now the end of the loop will be the previous end - 1.
         * Now the last position will be occupied by the gratest number
         */
        for (j = 0; j < ((size - i) - 1); j++)
        {
            /* if the second in the pair is grater than the first --> swap */
            if (array[j] > array[j + 1])
            {
                /* swap the values, now the second position in the window is the gratest of the two */
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
                print_array(array, size);
            }
        }
    }
}
