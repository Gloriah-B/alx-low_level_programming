#include <stdlib.h>
#include "main.h"
/**
 * malloc_checked - function allocates memory using malloc
 * @b: number of bytes to allocates
 *
 * Return: a pointer to the allocated memory
 * if malloc fails, status value is equal to 98.
 */
void *malloc_checked(unsigned int b)
{
	char *q;

	q = malloc(b);
	if (q == NULL)
		exit(98);
	return (q);
}
