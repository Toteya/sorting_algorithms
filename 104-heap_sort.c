#include "sort.h"
#include <stddef.h>

void heapify_down(int *array, size_t size, size_t parent);
void swap(int *x, int *y);

/**
 * heap_sort - sorts an array in ascending order using heapsort
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	/* creates max heap */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify_down(array, i, size);

	/* sorts heap */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify_down(array, 0, i);
	}

}

/**
 * heapify_down - Adjusts the max heap property from the given parent index
 * @array: original array
 * @size: size of the heap
 * @parent: index of the parent node
 * Return: Nothing
 */
void heapify_down(int *array, size_t parent, size_t size)
{
	size_t largest = parent;
	size_t left_child = 2 * parent + 1;
	size_t right_child = 2 * parent + 2;

	if (left_child < size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != parent)
	{
		swap(&array[largest], &array[parent]);
		heapify_down(array, largest, size);
	}
}

/**
 * swap - swaps two elements
 * @x: 1st variable to be swapped
 * @y: 2nd variable to be swapped
 * Return: Nothing
 */
void swap(int *x, int *y)
{
	int tmp;
	
       	tmp = *x;
	*x = *y;
	*y = tmp;
}
