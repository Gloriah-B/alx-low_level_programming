#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 *
 * @n: pointer to an unsigned long int
 * @index: index of the bit you want to set
 *
 * Return: 1 if it worked, -1 for an error
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int z;

	if (index > 63)
		return (-1);

	z = 1 << index;
	*n = (*n | z);

	return (1);
}

