#include "palindrome.h"

/**
* is_palindrome - checks whether or not a given unsigned integer is a palindrome
* @n: number
* Return: 1 if n is a palindrome
*/

int is_palindrome(unsigned long n)
{
	unsigned long int div = 1;

	while (n / div >= 10)
		div *= 10;

	while (n != 0)
	{
		unsigned long int lead = n / div;
		unsigned long int tail = n % 10;

		if (lead != tail)
			return (0);
		n = (n % div) / 10;
		div = div / 100;
	}
	return (1);
}
