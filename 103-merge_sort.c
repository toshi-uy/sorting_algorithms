#include "sort.h"
#include "swap.c"

/**
 * biggest_num - function to get the biggest
 * number in the array
 * @array: array of integers
 * @size: size of array
 * Return: the biggest number.
 */

void merge_rec(int *array, int start, int end, int aux[])
{
    int mid;
    int pointer_left;       // pointer_left points to the beginning of the left sub-array
    int pointer_right;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    if (end <= start)
        return;
    mid = (end - start)/2;
    merge_rec(array, start, mid, aux);
    merge_rec(array, mid + 1, end, aux);

    pointer_left = start;
    pointer_right = mid + 1;
    // we loop from i to j to fill each element of the final merged array
    for (k = start; k <= end; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = array[pointer_right];
            pointer_right++;
        } else if (pointer_right == end + 1) {        // right pointer has reached the limit
            aux[k] = array[pointer_left];
            pointer_left++;
        } else if (array[pointer_left] < array[pointer_right]) {        // pointer left points to smaller element
            aux[k] = array[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = array[pointer_right];
            pointer_right++;
        }
    }

    for (k = start; k <= end; k++) {      // copy the elements from aux[] to a[]
        array[k] = aux[k];
    }
}

void merge_sort(int *array, size_t size)
{
    int i = 0, j = 0, aux[100];
    j = size;

    merge_rec(array, i, j, aux);
}
