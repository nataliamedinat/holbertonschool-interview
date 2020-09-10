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

/**
 * binary_search - regular binary search
 *
 * @array: array 
 * @left: left
 * @right: right
 * @value: value to search for
 *
 * Return: Index or -1
 */

int binary_search(int *array, size_t left, size_t right, int value)
{
	int mid;

	if (left < right)
	{
		print_array(array, left, right);
		mid = left + (right - left) / 2;
		if (array[mid] >= value)
			return (binary_search(array, left, mid, value));
		return (binary_search(array, mid + 1, right, value));
	}
	if (array[left] == value)
		return (left);
	print_array(array, left, right);
	return (-1);
}
/**
* advanced_binary - function that searches for a value in a sorted array of integers
 *
 * @array: pointer to dirst element of the array
 * @size: size of array
 * @value: value to search for
 *
 * Return: Index of first occurence or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	int result;

	if (!array || size == 0)
		return (-1);
	result = binary_search(array, 0, size - 1, value);
	return (result);
}
