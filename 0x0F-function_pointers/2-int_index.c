#include "function_pointers.h"

/**
 * int_index - Find the index of the first element in an array that
 *             satisfies a given condition.
 * @array: Array of integers.
 * @size: Size of the array.
 * @cmp: Pointer to a function that checks the condition.
 *
 * Return: Index of the first element for which the cmp function returns true.
 *         If no such element is found, return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
	{
		int i;


		if (array == NULL || size <= 0 || cmp == NULL)
			return (-1);


		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]))
				return (i);
		}
		return (-1);
	}

