#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_array - Create array and initialize with specific character
 * @size: The size of the array.
 * @c: The character to initialize the array with.
 *
 * Return: A pointer to the array, or NULL if it fails.
 */
char *create_array(unsigned int size, char c)
{
	if (size == 0)
		return (NULL);

	char *result = (char *)malloc((size + 1) * sizeof(char));

	if (result == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		result[i] = c;
	}
	result[size] = '\0'; /* Null-terminate the string */

	return (result);
}

int main(void);

{
	unsigned int size = 5;
	char c = 'A';

	char *create_array = create_array(size, c);

	if (create_array != NULL)
	{
		printf("%s\n", create_array); /* Output: "AAAAA" */
		free(create_array); /* Remember to free the memory when done */
	}
	else
	{
	printf("Array creation failed.\n");
	}

	return (0);
}
