#include "menger.h"

/**
 * menger - print a menger sponge
 * @level: Level of the menger sponge
 */

void menger(int level)
{
	int i, j, pow_result, divI, divJ;
	char ch;

	pow_result = pow(3, level);

	for (i = 0; i < pow_result; i++)
	{
		for (j = 0; j < pow_result; j++)
		{
			ch = '#';
			divI = i;
			divJ = j;
			while (divI > 0)
			{
				if (divI % 3 == 1 && divJ % 3 == 1)
					ch = ' ';
				divI /= 3;
				divJ /= 3;
			}
			printf("%c", ch);
		}
		printf("\n");
	}
}
