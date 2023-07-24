#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	/* int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7}; */
	int array[] = {1, 5, 3, 1, 0, 0, 1, 5, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	counting_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
