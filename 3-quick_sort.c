#include "sort.h"

void sort(int *array, size_t first_idx, size_t last_idx, size_t size);

/**
 * quick_sort - Sort an array of integers in ascending order using the
 * quicksort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	size_t first_idx = 0;
	size_t last_idx = size - 1;

	if (!array && size <= 1)
		return;

	sort(array, first_idx, last_idx, size);
}

/**
 * sort - sort the sub-array using quicksort algorithm
 * @array: The original array containg the sub-array to be sorted
 * @first_idx: The lower bound of the sub-array
 * @last_idx: The upper bound of the sub-array
 * @size: The size of the original array
 *
 * Return: Nothing.
 */
void sort(int *array, size_t first_idx, size_t last_idx, size_t size)
{
	size_t i, j, pivot;
	int tmp;

	i = first_idx;
	pivot = last_idx;

	while (array[i] < array[pivot])
		i++;

	j = i;
	while (j < pivot)
	{
		j++;
		while (array[j] >= array[pivot] && j < pivot)
			j++;

		if (j == pivot)
			break;

		/* swap */
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
		print_array(array, size);

		i++;
	}

	if (i != pivot)
	{
		/* swap */
		tmp = array[pivot];
		array[pivot] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}

	/* sort the left sub-array */
	if (i - first_idx > 1)
		sort(array, first_idx, i - 1, size);
	/* sort the right sub-array */
	if (last_idx - i > 1)
		sort(array, i + 1, last_idx, size);
}
