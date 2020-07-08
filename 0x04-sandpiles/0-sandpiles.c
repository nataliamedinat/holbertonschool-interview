#include "sandpiles.h"

/**
 * changes - changes the grid to sampile
 * @grid1: sandpiles stable
 * Return: void
 */

void changes(int grid1[3][3])
{
	int i, j;
	int gridTemporal[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			gridTemporal[i][j] = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1 >= 0) && (i - 1 < 3))
					gridTemporal[i - 1][j] += 1;
				if ((j - 1 >= 0) && (j - 1 < 3))
					gridTemporal[i][j - 1] += 1;
				if ((i + 1 >= 0) && (i + 1 < 3))
					gridTemporal[i + 1][j] += 1;
				if ((j + 1 >= 0) && (j + 1 < 3))
					gridTemporal[i][j + 1] += 1;
			}
		}
	}

	add_grids(grid1, gridTemporal);
}

/**
 * print_grid - print
 * @grid: sandpiles
 * Return: void
 */

void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_grids - computes the sum of two grids
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 * Return: void
 */

void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
	for (j = 0; j < 3; j++)
		grid1[i][j] = grid1[i][j] + grid2[i][j];
	}
}

/**
 * is_stable - check if the grid is a stable
 * @grid1: sandpiles
 * Return: true otherwise false
 */

int is_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid1[i][j] > 3)
				return (0);
	return (1);
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles
 * @grid1: sandpiles stable
 * @grid2: sandpiles stable
 * Return: void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_grids(grid1, grid2);

	while (!is_stable(grid1))
	{
		print_grid(grid1);
		changes(grid1);
	}
}
