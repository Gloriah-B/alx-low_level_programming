#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - function prints a name using pointer to function
 * @name: string to add
 * @f: pointer to function
 * Return: 0
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
