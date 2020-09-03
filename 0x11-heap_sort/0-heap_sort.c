#include "sort.h"

/**
 * swap - Function to swap to nodes
 * @array: list
 * @size: size of array
 * @i: root
 * @s: size
 *
 * Return: Nothing
 */
void swap(int *array, int size, int i, int s)
{
	int largest = i, temp;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < size && array[l] > array[largest])
		largest = l;
	if (r < size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		print_array(array, s);
		swap(array, size, largest, s);
	}
}

/**
 * heap_sort - Function that sorts an array of ints in ascending order
 * @array: list
 * @size: size of array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i, temp;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		swap(array, size, i, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i != 0)
			print_array(array, size);
		swap(array, i, 0, size);
	}
}
