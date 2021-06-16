#include "sort.h"
#include "swap.c"

/**
 * biggest_num - function to get the biggest
 * number in the array
 * @array: array of integers
 * @size: size of array
 * Return: the biggest number.
 */

void merge_rec(int *array, int start, int end, int *aux)
{
    int mid;

    if (j <= i)
        return;
    mid = (j - i)/2;
    merge_rec(array, i, mid, aux);
    merge_rec(array, mid + 1, j, aux);
}

void merge_sort(int *array, size_t size)
{
    int i = 0, j = 0, mid = 0, *aux;
    j = size;

    merge_rec(array, i, j, aux);
}


function merge_sort(i, j, a, aux) {
 mid = (i + j) / 2
 merge_sort(i, mid, a, aux)
 merge_sort(mid + 1, j, a, aux)
 pointer_left = i, pointer_right = mid + 1
 for k in [i ... j] {
 if pointer_left points to smaller element, aux[k] = a[pointer_left] and increment pointer_left by 1
 if pointer_right points to smaller element, aux[k] = a[pointer_right] and increment pointer_right by 1
 }
 copy the contents of aux[i .. j] to a[i .. j]
}