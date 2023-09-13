#include <stdio.h>
#include <stdlib.h>
#include "function_pointers.h"

/**
 * array_iterator - applies a function to each element of an array
 * @array: array of integers
 * @size: how many elem to print
 * @action: pointer to a function that takes an integer as an argument
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array == NULL || action == NULL)
	{
		exit(1);
	}

	for (size_t i = 0; i < size; i++)
	{
		action(array[i]);
	}

	return (array);

}
