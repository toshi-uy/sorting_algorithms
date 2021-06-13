#include"sort.h"

/**
 * swap - swap to integers in an array
 * @array: the array to be sorted
 * @pos1: position of integer to swap
 * @pos2: position of integer to swap
 */

void swap(int *array, size_t pos1, size_t pos2)
{
    int tmp;

    tmp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = tmp;
}
