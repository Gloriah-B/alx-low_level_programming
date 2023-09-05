#include "main.h"
#include <stdlib.h>

/**
 * create_array - function creates array of size and assign char c
 * @size: pointer to size of array
 * @c: pointer to character to assign
 * Return: pointer to array, NULL if fail
 */

char *create_array(unsigned int size, char c)

{
	char *strg;
	unsigned int i;

	strg = malloc(sizeof(char) * size);
	if (size == 0 || strg == NULL)
		return (NULL);

	for (i = 0; i < size; i++)

	strg[i] = c;
	return (strg);
}

