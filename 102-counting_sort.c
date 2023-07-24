#include "sort.h"

/**
 * counting_sort - Sorts an array of positive integers using the counting
 * sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing.
 */
void counting_sort(int *array, size_t size)
{
	size_t i, new_idx;
	int j, max, *freq_array, *sorted_array;

	if (!array)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	freq_array = malloc(sizeof(int) * (max +  1));
	if (!freq_array)
		exit(EXIT_FAILURE);

	for (i = 0; i < size; i++)
		freq_array[array[i]]++;
	for (j = 1; j < max + 1; j++)
		freq_array[j] += freq_array[j - 1];
	print_array(freq_array, max + 1);
	for (j = max; j > 0; j--)
		freq_array[j] = freq_array[j - 1];
	freq_array[0] = 0;

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
		exit(EXIT_FAILURE);

	for (i = 0; i < size; i++)
	{
		new_idx = freq_array[array[i]];
		sorted_array[new_idx] = array[i];
		freq_array[array[i]]++;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(freq_array);
	free(sorted_array);
}
