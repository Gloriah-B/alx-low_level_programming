#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid - function that frees 2d grid
 * @grid: pointer to the 2d grid
 * @height: height dimension of grid
 * Return: 0
 */
void free_grid(int **grid, int height)

{
	int j;

	for (j = 0; j < height; j++)
	{
		free(grid[j]);

	}

	free(grid);
}
