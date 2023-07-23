#include "sort.h"

void sort_partition(int *array, size_t start, size_t end, size_t size);

/**
 * quick_sort_hoare - sorts an array in ascending order using
 * the quick_sort hoare algorithm
 * @array: the array to be sorted
 * @size: size of the array
 * Return: Nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
	size_t start, end;

	if (array == NULL)
		return;

	start = 0;
	end = size - 1;

	sort_partition(array, start, end, size);
}

/**
 * sort_partition - sorts the partition of the array
 * @array: array containing the partition
 * @size: size of the array
 * @start: start of the partition
 * @end: end of parttion
 * Return: Nothing
 */

void sort_partition(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot, i, j;
	int tmp;

	pivot = end;
	i = start;
	j = end - 1;

	while (j >= i)
	{
		while (array[i] <= array[pivot] && i < pivot)
			i++;
		while (array[j] >= array[pivot] && j > i)
			j--;

		if (j <= i || i == pivot)
			break;

		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}

	if (i != pivot)
	{
		tmp = array[i];
		array[i] = array[pivot];
		array[pivot] = tmp;
		print_array(array, size);
	}

	if ((i - start) > 1)
		sort_partition(array, start, i - 1, size);
	if ((end - i) > 1)
		sort_partition(array, i + 1, end, size);
}
