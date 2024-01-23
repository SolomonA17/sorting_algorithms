#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
* TDMerge - combine and arrange the subarrays
* @start: starting index
* @middle: middle index
* @end: ending index
* @dest: destination array
* @source: source array
*
* Return: void
*/
void TDMerge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
    size_t i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(source + start, middle - start);
    printf("[right]: ");
    print_array(source + middle, end - middle);
    i = start;
    j = middle;
    for (k = start; k < end; k++)
    {
        if (i < middle && (j >= end || source[i] <= source[j]))
        {
            dest[k] = source[i];
            i++;
        }
        else
        {
            dest[k] = source[j];
            j++;
        }
    }
    printf("[Done]: ");
    print_array(dest + start, end - start);
}

/**
* TDSplitMerge - recursively divide, merge, and organize the array
* @start: starting index (inclusive)
* @end: ending index (exclusive)
* @array: array to be sorted
* @clone: a duplicate of the array
*/
void TDSplitMerge(size_t start, size_t end, int *array, int *clone)
{
    size_t middle;

    if (end - start < 2)
        return;
    middle = (start + end) / 2;
    TDSplitMerge(start, middle, array, clone);
    TDSplitMerge(middle, end, array, clone);
    TDMerge(start, middle, end, array, clone);
    for (middle = start; middle < end; middle++)
        clone[middle] = array[middle];
}

/**
* merge_sort - organize an array of integers using the Merge Sort algorithm
* @array: array to be sorted
* @size: size of the array
*
* Return: void
*/
void merge_sort(int *array, size_t size)
{
    size_t i;
    int *clone;

    if (array == NULL || size < 2)
        return;
    clone = malloc(sizeof(int) * size);
    if (clone == NULL)
        return;
    for (i = 0; i < size; i++)
        clone[i] = array[i];
    TDSplitMerge(0, size, array, clone);
    free(clone);
}

