#include "sort.h"

void merge(int *array, int *l_array, int l_size, int *r_array, int r_size);

/**
 * merge_sort - sorts an array of integers in ascending order using merge sort
 * @array: the array to be sorted
 * @size: size of array
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *left_array, *right_array;
	size_t mid, i;

	if (array == NULL || size <= 1)
		return;

	mid = size / 2;
	left_array = (int *)malloc(mid * sizeof(int));
	right_array = (int *)malloc((size - mid) * sizeof(int));

	/* Copy elements to left & right arrays */
	for (i = 0; i < mid; i++)
		left_array[i] = array[i];
	for (i = mid; i < size; i++)
		right_array[i - mid] = array[i];
	merge_sort(left_array, mid);
	merge_sort(right_array, size - mid);

	merge(array, left_array, mid, right_array, size - mid);

	printf("Merging...\n[left]: ");
	print_array(left_array, mid);
	printf("[right]: ");
	print_array(right_array, size - mid);

	printf("[Done]: ");
	print_array(array, size);

	free(left_array);
	free(right_array);
}

/**
 * merge - merges two sub-arrays in ascending order
 * @array: the original array
 * @l_array: the left sub-array
 * @l_size: size of left sub-array
 * @r_array: the right sub-array
 * @r_size: size of right sub-array
 * Return: Nothing
 */
void merge(int *array, int *l_array, int l_size, int *r_array, int r_size)
{
	int *new_array;
	int i = 0, j = 0, k = 0;

	new_array = (int *)malloc((l_size + r_size) * sizeof(int));

	if (new_array == NULL)
	{
		printf("Memory allocation error.\n");
		return;
	}

	while (i < l_size && j < r_size)
	{
		if (l_array[i] <= r_array[j])
		{
			new_array[k] = l_array[i];
			i++;
		}
		else
		{
			new_array[k] = r_array[j];
			j++;
		}
		k++;
	}

	while (i < l_size)
	{
		new_array[k] = l_array[i];
		i++;
		k++;
	}

	while (j < r_size)
	{
		new_array[k] = r_array[j];
		j++;
		k++;
	}
	for (i = 0; i < l_size + r_size; i++)
	{
		array[i] = new_array[i];
	}

	free(new_array);
}
