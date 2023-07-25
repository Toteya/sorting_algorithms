#include "sort.h"

size_t exponent(size_t a, size_t b);
int get_digit(int num, int n);
void csort(int *array, size_t size, int n);

/**
 * radix_sort - Sorts an array of integers using the radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int max, digits;
	size_t i;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	i = 1;
	digits = max;
	while (digits > 0)
	{
		csort(array, size, i);
		digits /= 10;
		i++;
		print_array(array, size);
	}
}


/**
 * csort - Sorts an array of integers according to the specified nth digit
 * of the figures base on the figure using the counting sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 * @n: the digit by which to sort
 *
 * Return: Nothing.
 */
void csort(int *array, size_t size, int n)
{
	size_t i, new_idx;
	int j, max = 0, *freq_array = NULL, *sorted_array = NULL;

	if (!array || size < 2)
		return;
	max = get_digit(array[0], n);
	for (i = 0; i < size; i++)
	{
		if (get_digit(array[i], n) > max)
			max = get_digit(array[i], n);
	}
	freq_array = malloc(sizeof(int) * (max +  1));
	if (!freq_array)
		exit(EXIT_FAILURE);

	for (j = 0; j < max + 1; j++)
		freq_array[j] = 0;

	for (i = 0; i < size; i++)
		freq_array[get_digit(array[i], n)]++;
	for (j = 1; j < max + 1; j++)
		freq_array[j] += freq_array[j - 1];
	for (j = max; j > 0; j--)
		freq_array[j] = freq_array[j - 1];
	freq_array[0] = 0;

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(freq_array);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < size; i++)
	{
		new_idx = freq_array[get_digit(array[i], n)];
		sorted_array[new_idx] = array[i];
		freq_array[get_digit(array[i], n)]++;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(freq_array);
	free(sorted_array);
}

/**
 * get_digit - Returns the nth digit of an integer
 * @num: The integer whose nth digit is to be returned
 * @n: the place of the digit
 *
 * Return: The digit
 */
int get_digit(int num, int n)
{
	return ((num % exponent(10, n)) / exponent(10, n - 1));
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
