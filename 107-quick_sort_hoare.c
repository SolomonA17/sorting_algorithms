#include "sort.h"
/**
* partition - applies quicksort using the Hoare version
* @array: array to be sorted
* @min: lowest index
* @max: highest index
* @size: size of the array
*
* Return: partition index
*/
size_t partition(int *array, ssize_t min, ssize_t max, size_t size)
{
	int swap, pivot;

	pivot = array[max];
	while (min <= max)
	{
		while (array[min] < pivot)
			min++;
		while (array[max] > pivot)
			max--;
		if (min <= max)
		{
			if (min != max)
			{
				swap = array[min];
				array[min] = array[max];
				array[max] = swap;
				print_array(array, size);
			}
			min++;
			max--;
		}
	}
	return (max);
}

/**
* quicksort - sorts a partition of an array of integers
* @array: array to be sorted
* @min: lowest index of the partition to be sorted
* @max: highest index of the partition to be sorted
* @size: size of the array
*
* Return: void
*/
void quicksort(int *array, ssize_t min, ssize_t max, size_t size)
{
	ssize_t pivot;

	if (min < max)
	{
		pivot = partition(array, min, max, size);
		quicksort(array, min, pivot, size);
		quicksort(array, pivot + 1, max, size);

	}
}

/**
* quick_sort_hoare - sorts an array of integers with the quick sort algorithm (Hoare version)
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}

