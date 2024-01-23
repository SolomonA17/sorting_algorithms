#include "sort.h"


/**
 * partition - arrange an array of integers in ascending order using quick_sort
 *              Lomuto implementation with pivot in the last element of the partition
 * @array: array to be arranged
 * @min: minimum value index
 * @max: maximum value index
 * @size: the size of the array to be arranged
 * Return: index + 1
 */
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
    ssize_t i, j;
    int swap, pivot;

    pivot = array[max];
    i = min - 1;
    for (j = min; j < max; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap = array[i];
                array[i] = array[j];
                array[j] = swap;
                print_array(array, size);
            }
        }
    }
    if (array[max] < array[i + 1])
    {
        swap = array[i + 1];
        array[i + 1] = array[max];
        array[max] = swap;
        print_array(array, size);
    }
    return (i + 1);
}

/**
* quicksort - organizes an array (partitions it recursively)
* @array: array to be organized
* @min: minimum index of the partition
* @max: maximum index of the partition
* @size: array size
*/
void quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
    ssize_t pivot;

    if (min < max)
    {
        pivot = partition(array, min, max, size);
        quicksort(array, min, pivot - 1, size);
        quicksort(array, pivot + 1, max, size);
    }
}

/**
* quick_sort - organizes an array using the quick sort algorithm
* @array: The array to be organized
* @size: The size of the array to be organized
*/
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quicksort(array, 0, size - 1, size);
}

