#include <stdio.h>
#include "main.h"
/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if invalid input.
 */
unsigned int binary_to_uint(const char *b)
{
	if (b == NULL)
		return (0);

	unsigned int result = 0;

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0); /* Invalid character found, return 0 */

		result = result * 2 + (*b - '0');
		b++;
	}

	return (result);
}
