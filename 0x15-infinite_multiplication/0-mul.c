#include "holberton.h"

/**
 * isInt - Determines if it is an integer
 * @c: Pointer to array of characters
 *
 * Return: 0 if not an integer, otherwise 1.
 */

int isInt(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

/**
 * _strlen - Finds length of @c
 * @c: Pointer to array of characters
 *
 * Return: Length of @c.
 */

int _strlen(char *c)
{
	char *p = c;

	while (*c)
	{
		c++;
	}

	return (c - p);
}

/**
 * _calloc - Reserves space in memory and fills it with 0
 * @nmemb: Number of elements (members)
 * @size: Size of the element
 * Return: Void
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *array;

	if (nmemb == 0 || size == 0)
		return (NULL);

	array = malloc(nmemb * size);
	if (!array)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		*(array + i) = 0;

	return (array);
}

/**
 * inf_mult - Multiplies two integers and prints the product.
 * @num1: Array of ints that makes up the first number
 * @num2: Array of ints that makes up the second number
 * Return: Void
 */

void inf_mult(char *num1, char *num2)
{
	int len1, len2, total, num1_dig, num2_dig, temp;
	int residual = 0;
	int *ptr = NULL;
	int i;

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	total = len1 + len2;
	/** printf("%i", total);*/
	temp = len2;

	ptr = _calloc(sizeof(int), total);

	for (len1--; len1 >= 0; len1--)
	{
		/** Replacing 0s with digit value of num1 */
		num1_dig = num1[len1] - '0';
		residual = 0;
		len2 = temp;
		for (len2--; len2 >= 0; len2--)
		{
			num2_dig = num2[len2] - '0';
			residual += ptr[len1 + len2 + 1] +
				(num1_dig * num2_dig);
			ptr[len1 + len2 + 1] = residual % 10;
			residual /= 10;
		}
		if (residual)
			ptr[len1 + len2 + 1] = residual % 10;
	}
	while (*ptr == 0)
	{
		ptr++;
		total--;
	}
	for (i = 0; i < total; i++)
		printf("%i", ptr[i]);
	printf("\n");
}

/**
 * main - Multiplies two positive numbers.
 * @argc: Arguments count. (Number of arguments)
 * @argv: Vector of arguments.
 * Return: 98 if there is an error, otherwise the product of the multiplication
 */

int main(int argc, char **argv)
{
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3 || !isInt(num1) || !isInt(num2))
	{
		printf("Error\n");
		exit(98);
	}

	if (*num1 == 48 || *num2 == 48)
		printf("0\n");
	else
		inf_mult(num1, num2);

	return (0);
}
