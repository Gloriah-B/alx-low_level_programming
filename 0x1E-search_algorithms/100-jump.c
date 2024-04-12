#include <stdio.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using
 *               the Jump search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 *         in array or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return(-1);

	int step = sqrt(size);
	int prev = 0;

	while (array[step] < value && step < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", step, array[step]);
		prev = step;
		step += sqrt(size);
	}

	printf("Value found between indexes [%d] and [%d]\n", prev, step);

	for (int i = prev; i <= step && i < (int)size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return(i);
	}

	return(-1);
}
