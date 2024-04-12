#include <stdio.h>

/**
 * binary_search - Searches for a value in a sorted array of integers using
 *                 the Binary search algorithm
 * @array: A pointer to the first element of the array to search in
 * @size: The number of elements in the array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if value is not present
 *         in the array or if array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, mid, i;

	if (!array || size == 0)
		return (-1);

	while (left <= right)
	{
		printf("Searching in array:");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(",");
		}
		printf("\n");

		mid = left + (right - left) / 2;

		if (array[mid] == value)
		{
			if ((mid == 0 || array[mid - 1] != value) &&
			    (mid == size - 1 || array[mid + 1] != value))
				return (mid);
			else if (array[mid + 1] == value)
				left = mid + 1;
			else
				right = mid - 1;
		}
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;

		if ((left == 0 && array[left] != value) ||
		    (right == size - 1 && array[right] != value) ||
		    (value < array[left] || value > array[right]))
			return (-1);
	}

	return (-1);
}
