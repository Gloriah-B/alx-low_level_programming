#include "main.h"

/**
 * get_endianness - functionchecks the endianness
 * Return: 0 for big, 1 for little endian
 */
int get_endianness(void)
{
	unsigned int y = 1;
	char *c = (char *) &y;

	return (*c);
}
