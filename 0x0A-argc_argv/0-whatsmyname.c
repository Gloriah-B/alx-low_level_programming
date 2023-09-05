#include <stdio.h>
#include "main.h"

/**
 * main - Entry point of the program
 * @argc: arguments that have an array of string
 * @argv: pointer to command line argument
 * Return: Always 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}

