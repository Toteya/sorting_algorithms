#include "sort.h"

/**
 * bubble_sort - Sorts an array using the bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array (number of elements)
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int tmp;
	int sorted = 0;

	while (!sorted)
	{
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}
