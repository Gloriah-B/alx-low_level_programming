#include "main.h"
#include <unistd.h>
/**
 * _putchar - function writes the chrctr c to stdout
 * @c: pointer to character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

