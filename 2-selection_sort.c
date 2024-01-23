#include "sort.h"
/**
 * selection_sort - arrange an array of integers in ascending order using
 *                  the selection sort algorithm
 *
 * @array: the array to be arranged
 * @size: the size of the array to be arranged
 */
void selection_sort(int *array, size_t size)
{
    unsigned long int i = 0, j = 0, smallest = 0;
    int *swap = NULL;

    if (!array || size < 2)
        return;
    for (; i < size; i++)
    {
        smallest = i; /* set the current element as the minimum */
        swap =  malloc(sizeof(int) * 1);
        *swap = *(array + i);
        for (j = i + 1; j < size; j++)
        {
            if (*(array + j) < *(array + smallest))
            {
                smallest = j; /* update the index of the minimum element */
            }
        }
        if (i < smallest)
        {
            *(array + i) = *(array + smallest);
            *(array + smallest) = *swap;
            free(swap);
            print_array(array, size);
        }
        else
            free(swap);
    }
}

