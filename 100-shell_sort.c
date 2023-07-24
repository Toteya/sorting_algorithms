#include "sort.h"

size_t exponent(size_t a, size_t b);

/**
 * shell_sort - Sorts an array of integers using the shell sort algorithm
 * with the Knuth interval sequence
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t position, i;
	size_t k, gap, _gap = 0;
	int tmp;

	if (!array)
		return;

	for (k = 0; _gap < size; k++)
	{
		gap = _gap;
		_gap = (exponent(3, k) - 1) / 2;
	}

	while (gap > 0)
	{
		for (position = gap; position < size; position++)
		{
			i = position;
			while (array[i] < array[i - gap] && i >= gap)
			{
				tmp = array[i];
				array[i] = array[i - gap];
				array[i - gap] = tmp;

				i -= gap;
			}
		}
		gap = gap / 3;
		print_array(array, size);
	}
}


/**
 * exponent - Returns the result of the exponentiation of two numbers
 * @a: The base
 * @b: The exponent
 *
 * Return: The result of a to the power of b (a ^ b)
 */
size_t exponent(size_t a, size_t b)
{
	if (b < 1)
		return (1);
	return (a * exponent(a, b - 1));
}
