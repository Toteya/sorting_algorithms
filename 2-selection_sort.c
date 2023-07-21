#include "sort.h"

/**
 * selection_sort - Sorts an array with selection sorting algorithm
 * and prints array after every swap
 * @array: The array to be printed
 * @size: The size of the array
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t smallest_idx, i, j;
	int tmp;

	if (array == NULL || size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		smallest_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_idx])
			{
				tmp = array[smallest_idx];
				array[smallest_idx] = array[j];
				array[j] = tmp;
				print_array(array, size);

				/* smallest_idx = j; */
			}
		}
/**
		if (smallest_idx != i)
		{
*/			/* swap elements */
/*			tmp = array[smallest_idx];
			array[smallest_idx] = array[i];
			array[i] = tmp;

			print_array(array, size);
		}
*/
	}
}
