#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)

{
	int **w;
	int x, y;

	if (width <= 0 || height <= 0)
	return (NULL);

	w = malloc(sizeof(int *) * height);

	if (w == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
{
	w[x] = malloc(sizeof(int) * width);
		if (w[x] == NULL)

		{
			for (y = 0; y < x; y++)
				free(w[x]);
			free(w);
			return (NULL);
		}
}
		for (x = 0; x < height; x++)
		{
			for (y = 0; y < width; y++)
				w[x][y] = 0;
		}
return (w);
}
/**
 * free_grid - frees memory for allocated grid
 * @grid: pointer to the grid
 * @height: grid height
 * Return: 0
 */
void free_grid(int **grid, int height)

{
	int x;

	if (grid != NULL)

	{
		for (x = 0; x < height; x++)
			free(grid[x]);
		free(grid);
	}
}
