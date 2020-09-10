#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - prints an array
 *
 * @array: array to print
 * @left: left
 * @right: right
 *
 * Return: nothing. void
 */

void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	for (; left <= right; left++)
	{
		printf("%i", array[left]);
		if (left < right)
			printf(", ");
	}
	printf("\n");
}


